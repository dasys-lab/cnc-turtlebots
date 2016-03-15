package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui;

import android.content.Context;
import android.util.AttributeSet;
import android.view.ContextMenu;
import android.view.MenuInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.github.ros_java.marauders_map.R;

/**
 * Created by marci on 15.03.16.
 */
public class MapView extends ImageView {
    public MapView(Context context) {
        super(context);
    }

    public MapView(Context context, AttributeSet attrs) {
        super(context, attrs, 0);
    }

    public MapView(Context context, AttributeSet attrs, int defStyle) {
        super(context,attrs,defStyle);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu) {
        super.onCreateContextMenu(menu);
        menu.add(R.string.nav_goal);
        menu.add(R.string.pose_estimate);
    }

    @Override
    public void setOnCreateContextMenuListener(OnCreateContextMenuListener l) {
        super.setOnCreateContextMenuListener(l);
    }
}
