package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity;

import android.app.Activity;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.os.Environment;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;

import com.esotericsoftware.yamlbeans.YamlReader;
import com.github.ros_java.marauders_map.R;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.AbstractMapOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.MapDrawer;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.RobotPositionOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.MapView;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.Command;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.GlobalCommandList;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.InitialPoseCommand;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.SendToGoalCommand;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import com.google.common.io.Files;

import org.apache.commons.io.IOUtils;
import org.ros.android.view.VirtualJoystickView;
import org.ros.internal.message.Message;
import org.ros.internal.message.RawMessage;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Map;

import geometry_msgs.Point;
import geometry_msgs.Pose;
import geometry_msgs.Quaternion;
import uk.co.senab.photoview.PhotoViewAttacher;

/**
 * Created by marci on 20.11.15.
 */
public class MapScreen extends Activity {

    // UI Elements
    private MapView mapView;
    private static Bitmap bitmap = null;
    private PhotoViewAttacher attacher;
    private Spinner robotsSpinner;
    private MapDrawer mapDrawer;

    // map details
    private static int width;
    private static int height;

    private Command activeCommand = null;


    // garment
    private ArrayAdapter<String> spinnerAdapter;
    private Thread thread;

    /**
     *
     * @param savedInstanceState
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getActionBar().setDisplayHomeAsUpEnabled(true);
        setContentView(R.layout.map_screen);
        //map = getPGMAsBitmap();
        // readMap from File
        if (getBitmap() == null) {
            try { // TODO FIX MYSTERIOUS MAP BUG URGENT
                int id = 1;
                String mapPath = Environment.getExternalStorageDirectory() + "/currentMap_" + id + ".pgm";
                writePGMResourceToFile(id);
                if(new File(mapPath).exists()) {
                    int[] mapArray = readPGMFile(mapPath);
                    bitmap = Bitmap.createBitmap(mapArray, width, height, Bitmap.Config.RGB_565);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }


        // init mapView
        mapView = (MapView) findViewById(R.id.imageView);
        //getMapView().setImageBitmap(getBitmap());
        ColorMatrix matrix = new ColorMatrix();
        matrix.setSaturation(0);
        float[] array = matrix.getArray();
        // TODO find right brightness for map
        array[4] = array[9] = array[14] = 150;
        matrix.set(array);

        // set grayscale filter, otherwise a blueish image would be shown because the of the bitmap are not correctly shifted
        ColorMatrixColorFilter filter = new ColorMatrixColorFilter(matrix);
        getMapView().setColorFilter(filter);

        // Init spinner for robot selection
        robotsSpinner = (Spinner) findViewById(R.id.robotsSpinner);
        spinnerAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, android.R.id.text1);
        spinnerAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        robotsSpinner.setAdapter(spinnerAdapter);

        // attach PhotoView, which allows for easy zooming and scrolling auf the picture
        attacher = new PhotoViewAttacher(getMapView());
        attacher.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {

                registerForContextMenu(v);
                openContextMenu(v);
                unregisterForContextMenu(v);
                return true;
            }
        });
        attacher.setOnViewTapListener(new PhotoViewAttacher.OnViewTapListener() {
            @Override
            public void onViewTap(View view, float v, float v1) {

            }
        });


        Bitmap emptyMap = Bitmap.createBitmap(MapScreen.bitmap.getWidth(), MapScreen.bitmap.getHeight(), Bitmap.Config.RGB_565);
        Canvas canvas = new Canvas(emptyMap);
        mapView.setImageDrawable(new BitmapDrawable(getResources(),emptyMap));
        mapDrawer = new MapDrawer();
        mapDrawer.setMapView(mapView);
        YamlReader reader = null;
        try {
            reader = new YamlReader(new String(IOUtils.toByteArray(this.getResources().openRawResource(R.raw.map_final))));
            Object object = reader.read();
            System.out.println(object);
            Map<String, Object> stringObjectMap = (Map<String, Object>) object;

            ArrayList<String> origin = (ArrayList<String>) stringObjectMap.get("origin");
            double[] orgin = new double[3];
            int i = 0;
            for (String s : origin) {
                orgin[i++] = Double.parseDouble(s);
            }
            double resolution = Double.parseDouble((String) stringObjectMap.get("resolution"));

            AbstractMapOverlay.setOrigin(orgin);
            AbstractMapOverlay.setPixelToMeterResolution(resolution);
        } catch (IOException e) {
            e.printStackTrace();
        }

        RobotPositionOverlay robotPositionOverlay = new RobotPositionOverlay(mapView, MapScreen.bitmap,canvas);
        robotPositionOverlay.setListener(Root.getAmcl_poseListener());
        robotPositionOverlay.setParticleCloudListener(Root.getParticleCloudListener());
        Root.overlays.add(robotPositionOverlay);
        thread = new Thread(mapDrawer);
        thread.start();

        Root.getMaraudersMap().getPlanTreeInfoListener().setActivity(this);
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        super.onContextItemSelected(item);
        if(item.getTitle().equals(getResources().getString(R.string.nav_goal))) {
            activeCommand = GlobalCommandList.getCommandOfType(SendToGoalCommand.class);
            attacher.setOnPhotoTapListener(new PhotoViewAttacher.OnPhotoTapListener() {
                @Override
                public void onPhotoTap(View view, float x, float y) {
                    double pixelX = ((double) x) * width;
                    double pixelY = ((double) y) * height;
                    double[] meterForPixel = Root.overlays.get(0).getMeterForPixel(pixelX, pixelY);
                    activeCommand.sendMessage(meterForPixel);
                    attacher.setOnPhotoTapListener(null);
                }
            });
        } else if(item.getTitle().equals(getResources().getString(R.string.pose_estimate))) {
            activeCommand = GlobalCommandList.getCommandOfType(InitialPoseCommand.class);
            attacher.setOnPhotoTapListener(new PhotoViewAttacher.OnPhotoTapListener() {

                double[] point1 = null;

                @Override
                public void onPhotoTap(View view, float x, float y) {
                    double pixelX = ((double) x) * width;
                    double pixelY = ((double) y) * height;
                    double[] meterForPixel = Root.overlays.get(0).getMeterForPixel(pixelX, pixelY);
                    if (point1 != null) {
                        activeCommand.sendMessage(new double[]{point1[0], point1[1], meterForPixel[0], meterForPixel[1]});
                        attacher.setOnPhotoTapListener(null);
                    } else {
                        point1 = meterForPixel;
                    }
                }
            });
        }
        return true;
    }

    /**
     *
     * @param filename
     * @return
     * @throws IOException
     */
    public static int[] readPGMFile(String filename) throws IOException
    {
        byte[] scanner = Files.toByteArray(new File(filename));
        String precision  = "";
        int endOfPrecision = 0;
        int max= 0;
        // read beginning from byte number 33
        for(int i = 33; Character.isDigit((char)(scanner[i]))  || (char)(scanner[i]) == '.';i++,endOfPrecision = i) {
            precision += (char)(scanner[i]);
        }

        //skip
        for(;!Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
        }

        //width
        for(;Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
            width = width*10 + Integer.parseInt("" + (char)(scanner[endOfPrecision]));
        }

        //skip
        for(;!Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
        }

        //height
        for(;Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
            height = height*10 + Integer.parseInt("" + (char)(scanner[endOfPrecision]));
        }

        //skip
        for(;!Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
        }

        //read maximum value (lays between 0 255)
        for(;Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
            max = max*10 + Integer.parseInt("" + (char)(scanner[endOfPrecision]));
        }

        // init occupancy array
        int[] colors = new int[scanner.length-endOfPrecision-1];

        for(int i=0; i < colors.length; i++,endOfPrecision++) {
            // shift colors
            colors[i] = scanner[endOfPrecision] & 0xFF;
        }

        return colors;
    }

    /**
     * This is for testing purposes only. later on this could be used to save incoming maps to file.
     * @param id
     * @throws Exception
     */
    public void writePGMResourceToFile(int id) throws Exception {
        final OutputStream outputStream = new FileOutputStream(new File(Environment.getExternalStorageDirectory() + "/currentMap_" + id + ".pgm"));

        final Resources resources = this.getResources();
        final byte[] largeBuffer = new byte[1024 * 4];
        int totalBytes = 0;
        int bytesRead = 0;

        final InputStream inputStream = resources.openRawResource(R.raw.my_map);
        while ((bytesRead = inputStream.read(largeBuffer)) > 0) {
            if (largeBuffer.length == bytesRead) {
                outputStream.write(largeBuffer);
            } else {
                final byte[] shortBuffer = new byte[bytesRead];
                System.arraycopy(largeBuffer, 0, shortBuffer, 0, bytesRead);
                outputStream.write(shortBuffer);
            }
            totalBytes += bytesRead;
        }
        inputStream.close();

        outputStream.flush();
        outputStream.close();
    }

    @Override
    public void finish() {
        super.finish();
    }

    public ImageView getMapView() {
        return mapView;
    }

    public static Bitmap getBitmap() {
        return bitmap;
    }

    public ArrayAdapter<String> getSpinnerAdapter() {
        return spinnerAdapter;
    }

    public void setSpinnerAdapter(ArrayAdapter<String> spinnerAdapter) {
        this.spinnerAdapter = spinnerAdapter;
    }
}
