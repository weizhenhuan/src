package AStar;

/**
 * File: Data.java
 * Author: LittleLittleWei
 * Time: 2020/5/21 15:46
 **/
public class Data {
    Point point;
    double g;
    double h;
    Data parent;

    public Data(Point p, double g, double h, Data parent)
    {
        this.point = p;
        this.g = g;
        this.h = h;
        this.parent = parent;
    }

    double f()
    {
        return g + h;
    }
}
