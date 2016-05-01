package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;

/**
 * Created by marci on 05.02.16.
 */
public class MapDrawer implements Runnable {

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            for (AbstractMapOverlay mapOverlay : Root.overlays) {
                mapOverlay.render();
            }
        }
    }
}
