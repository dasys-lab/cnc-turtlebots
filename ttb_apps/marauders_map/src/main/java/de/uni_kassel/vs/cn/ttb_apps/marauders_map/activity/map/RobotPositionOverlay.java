package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.widget.ImageView;


import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AMCL_PoseListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.ParticleCloudListener;

/**
 * Created by marci on 05.02.16.
 */
public class RobotPositionOverlay extends AbstractMapOverlay {

    private AMCL_PoseListener listener;

    private ParticleCloudListener particleCloudListener;

    private Point wobble = new Point();
    private Paint paint;

    /**
     * @param imageView     the overlay needs an ImageView to apply to.
     * @param underlyingMap the map on which will be drawn on top.
     */
    public RobotPositionOverlay(ImageView imageView, Bitmap underlyingMap, Canvas canvas) {
        super(imageView, underlyingMap, canvas);
        //Drawable drawable = imageView.getResources().getDrawable(R.drawable.bot);
        currentY = currentX = 40;
        paint = new Paint();
        paint.setColor(Color.GREEN);
        paint.setAlpha(100);
    }

    @Override
    public void render() {

        double[] currentPosition = getListener().getCurrentPosition();
        renderToMapPosition(currentPosition[0],currentPosition[1]);
    }

    @Override
    protected void drawOverlay(Canvas canvas) {
        //super.drawOverlay(canvas);
        canvas.drawCircle(Math.round(currentX), Math.round(currentY), 5, paint);
    }

    public AMCL_PoseListener getListener() {
        return listener;
    }

    public void setListener(AMCL_PoseListener listener) {
        this.listener = listener;
    }

    public ParticleCloudListener getParticleCloudListener() {
        return particleCloudListener;
    }

    public void setParticleCloudListener(ParticleCloudListener particleCloudListener) {
        this.particleCloudListener = particleCloudListener;
    }
}
