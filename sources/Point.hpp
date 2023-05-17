//
// Created by shani on 16/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_POINT_H
#define COWBOY_VS_NINJA_A_POINT_H

/// Class that represents a place of an character on the board

class Point {
public:
    Point(double x = 0, double y = 0) : _x(x), _y(y) {}

    // get another point and return the distance from the other point to this point
    double distance (Point& other);

    // print the point
    void print();

    // get current point, destination point and distance.
    // return the point which closet to the distance point and at most in 'distance' range
    static Point moveTowards(Point& curr, Point& dest, double dist);

private:
    double _x;
    double _y;
};


#endif //COWBOY_VS_NINJA_A_POINT_H
