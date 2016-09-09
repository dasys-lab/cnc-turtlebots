package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.widget.ImageView;

/**
 * Created by marci on 16.06.16.
 */
public class MapOverlay extends AbstractMapOverlay {
    /**
     * @param imageView     the overlay needs an ImageView to apply to.
     * @param underlyingMap the map on which will be drawn on top.
     * @param canvas
     */
    public MapOverlay(ImageView imageView, Bitmap underlyingMap, Canvas canvas) {
        super(imageView, underlyingMap, canvas);
    }

    @Override
    protected void drawOverlay(Canvas canvas) {
        canvas.drawBitmap(underlyinMap, 0, 0, null);
    }
}
