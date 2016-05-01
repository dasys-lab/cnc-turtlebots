package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.github.ros_java.marauders_map.R;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.model.Triple;

/**
 * Created by marci on 29.04.16.
 */
public class RobotSpinnerAdapter extends ArrayAdapter<Triple<String,Integer,Integer>>{
    private LayoutInflater inflater;

    public RobotSpinnerAdapter(Context context, int resource, int textViewResourceId) {
        super(context, resource, textViewResourceId);
        inflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        return createViewFromResource(position, convertView, parent);
    }

    private View createViewFromResource(int position, View convertView, ViewGroup parent) {
        View view;
        TextView text;
        ImageView imageView;

        if (convertView == null) {
            view = inflater.inflate(R.layout.spinner_rows, parent, false);
        } else {
            view = convertView;
        }

        text = (TextView) view.findViewById(R.id.robotName);
        imageView = (ImageView) view.findViewById(R.id.robotColor);

        Triple<String,Integer,Integer> item = getItem(position);
        text.setText("Robot" + " " + item.getThird());
        imageView.setBackgroundColor(item.getSecond());

        return view;
    }

    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent) {
        return createViewFromResource(position, convertView, parent);
    }

    private View getCustomView(int position, View convertView, ViewGroup parent) {
        View row = inflater.inflate(R.layout.spinner_rows, parent, false);
        TextView name        = (TextView)row.findViewById(R.id.robotName);
        ImageView robotColor = (ImageView)row.findViewById(R.id.robotColor);
        Triple<String, Integer, Integer> item = this.getItem(position);
        name.setText(item.getFirst() + " " + item.getThird());
        robotColor.setBackgroundColor(item.getSecond());
        return row;
    }
}
