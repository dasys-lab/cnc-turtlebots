package de.uni_kassel.vs.cn.ttb_apps.marauders_map.model;

/**
 * Created by marci on 29.04.16.
 */
public class Triple<A,B,C> {
    A first;
    B second;
    C third;

    public Triple(A a,B b,C c) {
        first = a;
        second = b;
        third = c;
    }

    public A getFirst() {
        return first;
    }

    public B getSecond() {
        return second;
    }

    public C getThird() {
        return third;
    }
}
