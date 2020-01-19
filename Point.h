//
// Created by shaked on 16/01/2020.
//

#ifndef MILESTONE2_POINT_H
#define MILESTONE2_POINT_H


class Point {
int x;
int y;
public:
    //Point();
    Point(int x, int y);
    int getX();
    int getY();
    bool operator==(Point p);
    //Point& operator=(const Point& other);
};


#endif //MILESTONE2_POINT_H
