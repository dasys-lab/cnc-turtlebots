package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.widget.ImageView;

/**
 * Created by marci on 05.02.16.
 */
public abstract class AbstractMapOverlay {

    private ImageView mapView;

    private Bitmap underlyinMap;

    protected int currentX;

    protected int currentY;
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

    /**
     *
     * @param x
     * @param y
     */
    protected void renderToMapPosition(int x, int y) {

        currentX = x;
        currentY = y;
        mapView.post(new Runnable() {
            @Override
            public void run() {
                canvas.drawBitmap(underlyinMap, 0, 0, null);
                drawOverlay(canvas);
            }
        });
    }

    protected void drawOverlay(Canvas canvas) {

        canvas.drawCircle(currentX,currentY, 10,paint);
    }

    public void render() {
        renderToMapPosition(currentX,currentY);
    }
}
