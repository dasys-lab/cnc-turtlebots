package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity;

import android.app.Activity;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;

import com.github.ros_java.marauders_map.R;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import com.google.common.io.Files;

import org.ros.android.view.VirtualJoystickView;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import uk.co.senab.photoview.PhotoViewAttacher;

/**
 * Created by marci on 20.11.15.
 */
public class MapScreen extends Activity {

    private ImageView imageView;

    private static Bitmap bitmap = null;
    private PhotoViewAttacher attacher;
    private Spinner robotsSpinner;
    private VirtualJoystickView joystickView;

    private static final int MAXVAL = 255;
    private static int width;
    private static int height;

    public ArrayAdapter<String> getSpinnerAdapter() {
        return spinnerAdapter;
    }

    public void setSpinnerAdapter(ArrayAdapter<String> spinnerAdapter) {
        this.spinnerAdapter = spinnerAdapter;
    }

    private ArrayAdapter<String> spinnerAdapter;

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
        if (bitmap == null) {
            try {
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


        // init imageView
        imageView = (ImageView) findViewById(R.id.imageView);
        imageView.setImageBitmap(bitmap);
        ColorMatrix matrix = new ColorMatrix();
        matrix.setSaturation(0);
        float[] array = matrix.getArray();
        // TODO find right brightness for map
        array[4] = array[9] = array[14] = 150;
        matrix.set(array);

        // set grayscale filter, otherwise a blueish image would be shown because the of the bitmap are not correctly shifted
        ColorMatrixColorFilter filter = new ColorMatrixColorFilter(matrix);
        imageView.setColorFilter(filter);

        // Init spinner for robot selection
        robotsSpinner = (Spinner) findViewById(R.id.robotsSpinner);
        spinnerAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, android.R.id.text1);
        spinnerAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        robotsSpinner.setAdapter(spinnerAdapter);

        // attach PhotoView, which allows for easy zooming and scrolling auf the picture
        attacher = new PhotoViewAttacher(imageView);
        attacher.setOnViewTapListener(new PhotoViewAttacher.OnViewTapListener() {
            @Override
            public void onViewTap(View view, float v, float v1) {

            }
        });
        Root.getMaraudersMap().getPlanTreeInfoListener().setActivity(this);
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
}
