//
// Created by shaked on 16/01/2020.
//

#ifndef MILESTONE2_POINT_H
#define MILESTONE2_POINT_H


class Point {
int x;
int y;
public:
    Point(int x, int y);
    bool operator==(Point p) {
        if (this->x == p.x && this->y == p.y) {
            return true;
        }
    }
};


#endif //MILESTONE2_POINT_H
