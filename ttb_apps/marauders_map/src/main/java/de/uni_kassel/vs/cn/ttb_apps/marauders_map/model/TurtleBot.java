package de.uni_kassel.vs.cn.ttb_apps.marauders_map.model;

import android.graphics.Color;

import java.util.Random;

/**
 * Created by marci on 01.04.16.
 */
public class TurtleBot {
    private int id;
    private int color;
    private double[] position = {0.0,0.0};

    public TurtleBot(int id) {
        this.id = id;
        color = Color.rgb(new Random().nextInt(256),new Random().nextInt(256),new Random().nextInt(256));
    }

    public int getColor() {
        return color;
    }

    public void setColor(int color) {
        this.color = color;
    }

    public double[] getPosition() {
        return position;
    }

    public void setPosition(double[] position) {
        this.position = position;
    }

    public int getId() {
        return id;
    }
}
