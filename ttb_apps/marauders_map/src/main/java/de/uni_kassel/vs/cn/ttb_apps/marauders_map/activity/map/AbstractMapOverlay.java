package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.Paint;
import android.widget.ImageView;

/**
 * Created by marci on 05.02.16.
 */
public abstract class AbstractMapOverlay {

    private static double[] origin;
    private static double pixelToMeterResolution;

    private ImageView mapView;

    private Bitmap underlyinMap;

    protected double currentX;

    protected double currentY;
    private final Canvas canvas;
    private Paint paint;

    /**
     *
     * @param imageView the overlay needs an ImageView to apply to.
     * @param underlyingMap the map on which will be drawn on top.
     */
    public AbstractMapOverlay(ImageView imageView, Bitmap underlyingMap, Canvas canvas) {
        this.mapView = imageView;
        this.underlyinMap = underlyingMap;
        this.canvas = canvas;
        paint =  new Paint(Paint.ANTI_ALIAS_FLAG);
        paint.setColor(Color.GREEN);
    }

    public void setPosition(int x, int y) {
        currentX = x;
        currentY = y;
    }

    private static boolean intialized = false;

    /**
     *
     * @param x
     * @param y
     */
    protected void renderToMapPosition(double x, double y) {

        double[] pixelForMeter = getPixelForMeter(x, y);
        currentX = pixelForMeter[0];
        currentY = pixelForMeter[1];
        mapView.post(new Runnable() {
            @Override
            public void run() {
                canvas.drawBitmap(underlyinMap, 0, 0, null);
                drawOverlay(canvas);
                mapView.invalidate();
            }
        });

    }

    protected abstract void drawOverlay(Canvas canvas);

        //canvas.drawCircle(currentX,currentY, 10,paint);


    public void render() {
        renderToMapPosition(currentX,currentY);
    }

    public static void setOrigin(double[] newOrigin) {
        origin = newOrigin;
    }

    public double[] getOrigin() {
        return origin;
    }

    public double getPixelToMeterResolution() {
        return pixelToMeterResolution;
    }

    public static void setPixelToMeterResolution(double newPixelToMeterResolution) {
        pixelToMeterResolution = newPixelToMeterResolution;
    }

    public double[] getPixelForMeter(double meterX, double meterY) {
        int height = mapView.getDrawable().getBounds().height();
        int width = mapView.getDrawable().getBounds().width();

        double xMetersFromOrigin = Math.abs(origin[0]) + meterX;
        double yMetersFromOrigin = Math.abs(origin[0]) + meterY;

        double Xpixels = xMetersFromOrigin / pixelToMeterResolution;
        double Ypixels = yMetersFromOrigin / pixelToMeterResolution;

        return new double[] {Xpixels, height - Ypixels};
    }
}
