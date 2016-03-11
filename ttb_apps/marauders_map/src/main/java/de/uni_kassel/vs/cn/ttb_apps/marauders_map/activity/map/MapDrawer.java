package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.widget.ImageView;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;

/**
 * Created by marci on 05.02.16.
 */
public class MapDrawer implements Runnable {

    private ImageView mapView;

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            for (AbstractMapOverlay mapOverlay : Root.overlays) {
                mapOverlay.render();
            }
        }
    }

    public void setMapView(ImageView mapView) {
        this.mapView = mapView;
    }
}
