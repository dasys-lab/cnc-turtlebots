package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.widget.ImageView;


import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.TurtleBot;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.AMCL_PoseListener;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.node.ParticleCloudListener;

/**
 * Created by marci on 05.02.16.
 */
public class RobotPositionOverlay extends AbstractMapOverlay {

    private AMCL_PoseListener listener;

    private ParticleCloudListener particleCloudListener;

    /**
     * @param imageView     the overlay needs an ImageView to apply to.
     * @param underlyingMap the map on which will be drawn on top.
     */
    public RobotPositionOverlay(ImageView imageView, Bitmap underlyingMap, Canvas canvas) {
        super(imageView, underlyingMap, canvas);
        //Drawable drawable = imageView.getResources().getDrawable(R.drawable.bot);
    }

    @Override
    protected void drawOverlay(Canvas canvas) {

        for (TurtleBot bot : Root.getRobotQueue()) {
            double[] currentPosition = bot.getPosition();
            double[] pixelForMeter = getPixelForMeter(currentPosition[0], currentPosition[1]);
            Paint paint = new Paint();
            paint.setColor(bot.getColor());
            canvas.drawCircle(Math.round(pixelForMeter[0]), Math.round(pixelForMeter[1]), 5
                    , paint);

        }
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
