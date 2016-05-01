package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.listeners;

import android.view.View;
import android.widget.AdapterView;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Root;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Triple;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.TurtleBot;

public class SelectedRobotListener implements AdapterView.OnItemSelectedListener {
    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        Triple<String,Integer,Integer> triple = (Triple<String, Integer, Integer>) parent.getItemAtPosition(position);
        for (TurtleBot bot : Root.getRobotQueue()) {
            if(bot.getId() == triple.getThird().intValue()) {
                Root.setActiveRobot(bot);
                break;
            }
        }
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {
        return;
    }
}