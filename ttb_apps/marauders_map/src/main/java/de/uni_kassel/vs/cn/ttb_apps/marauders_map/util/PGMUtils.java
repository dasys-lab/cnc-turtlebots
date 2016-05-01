package de.uni_kassel.vs.cn.ttb_apps.marauders_map.util;

import android.content.res.Resources;
import android.os.Environment;

import com.github.ros_java.marauders_map.R;
import com.google.common.io.Files;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MapScreen;

public class PGMUtils {
    /**
     * This is for testing purposes only. later on this could be used to save incoming maps to file.
     * @param id
     * @param mapScreen
     * @throws Exception
     */
    public static void writePGMResourceToFile(int id, MapScreen mapScreen) throws Exception {
        final OutputStream outputStream = new FileOutputStream(new File(Environment.getExternalStorageDirectory() + "/currentMap_" + id + ".pgm"));

        final Resources resources = mapScreen.getResources();
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
            MapScreen.setWidth(MapScreen.getWidth()*10 + Integer.parseInt("" + (char)(scanner[endOfPrecision])));
        }

        //skip
        for(;!Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
        }

        //height
        for(;Character.isDigit((char)(scanner[endOfPrecision]));endOfPrecision++) {
            MapScreen.setHeight(MapScreen.getHeight()*10 + Integer.parseInt("" + (char)(scanner[endOfPrecision])));
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
            colors[i] = scanner[endOfPrecision] | scanner[endOfPrecision] << 8;
        }

        return colors;
    }
}
