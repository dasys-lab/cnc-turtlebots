package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.os.Environment;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.Spinner;

import com.esotericsoftware.yamlbeans.YamlReader;
import com.github.ros_java.marauders_map.R;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.AbstractMapOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.MapDrawer;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map.RobotPositionOverlay;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.MapView;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.RobotSpinnerAdapter;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.Command;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.GlobalCommandList;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.InitialPoseCommand;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.command.SendToGoalCommand;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import com.google.common.io.Files;

import org.apache.commons.io.IOUtils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.util.PGMUtils;
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
    private RobotSpinnerAdapter spinnerAdapter;
    private Thread thread;

    public static int getWidth() {
        return width;
    }

    public static int getHeight() {
        return height;
    }

    public static void setWidth(int width) {
        MapScreen.width = width;
    }

    public static void setHeight(int height) {
        MapScreen.height = height;
    }

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
                PGMUtils.writePGMResourceToFile(id, this);
                if(new File(mapPath).exists()) {
                    int[] mapArray = PGMUtils.readPGMFile(mapPath);
                    bitmap = Bitmap.createBitmap(mapArray, width, height, Bitmap.Config.RGB_565);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }


        // init mapView
        mapView = (MapView) findViewById(R.id.imageView);
        //getMapView().setImageBitmap(getBitmap());
        /*ColorMatrix matrix = new ColorMatrix();
        matrix.setSaturation(0);
        float[] array = matrix.getArray();
        // TODO find right brightness for map
        array[4] = array[9] = array[14] = 150;
        matrix.set(array);

        // set grayscale filter, otherwise a blueish image would be shown because the of the bitmap are not correctly shifted
        ColorMatrixColorFilter filter = new ColorMatrixColorFilter(matrix);
        getMapView().setColorFilter(filter);*/

        // Init spinner for robot selection
        robotsSpinner = (Spinner) findViewById(R.id.robotsSpinner);
        spinnerAdapter = new RobotSpinnerAdapter(this,R.layout.spinner_rows,R.id.robotName);
        spinnerAdapter.setDropDownViewResource(R.layout.spinner_rows);
        robotsSpinner.setAdapter(spinnerAdapter);

        // attach PhotoView, which allows for easy zooming and scrolling auf the picture
        attacher = new PhotoViewAttacher(getMapView());
        attacher.setMaximumScale(10.0f);
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
                double[] point1 = null;

                @Override
                public void onPhotoTap(View view, float x, float y) {
                    double pixelX = ((double) x) * width;
                    double pixelY = ((double) y) * height;
                    double[] meterForPixel = Root.overlays.get(0).getMeterForPixel(pixelX, pixelY);
                    if (point1 != null) {
                        int id = Integer.parseInt(robotsSpinner.getSelectedItem().toString().split(" ")[1]);
                        activeCommand.sendMessage(id,new double[] { point1[0], point1[1], meterForPixel[0], meterForPixel[1]});
                        attacher.setOnPhotoTapListener(null);
                    } else {
                        point1 = meterForPixel;
                    }
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
                        int id = Integer.parseInt(robotsSpinner.getSelectedItem().toString().split(" ")[1]);
                        activeCommand.sendMessage(id,new double[]{point1[0], point1[1], meterForPixel[0], meterForPixel[1]});
                        attacher.setOnPhotoTapListener(null);
                    } else {
                        point1 = meterForPixel;
                    }
                }
            });
        }
        return true;
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

    public RobotSpinnerAdapter getSpinnerAdapter() {
        return spinnerAdapter;
    }

    public void setSpinnerAdapter(RobotSpinnerAdapter spinnerAdapter) {
        this.spinnerAdapter = spinnerAdapter;
    }
}
