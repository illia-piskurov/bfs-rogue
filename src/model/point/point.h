#ifndef POINT_H
#define POINT_H

struct Point {
    int x;
    int y;
    Point()
        : x(0)
        , y(0) {};
    Point(int x, int y)
        : x(x)
        , y(y) {};
};

#endif