//
// Created by shaked on 16/01/2020.
//

#include "Point.h"

//Point::Point() {}
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;

}

bool Point::operator==(Point p) {
  if (this->x == p.x && this->y == p.y) {
    return true;
  }
  return false;
}

int Point::getX() {
  return this->x;
}
int Point::getY() {
  return this->y;
}
/*
Point& Point::operator=(const Point &other) {
  this->x = other.x;
  this->y = other.y;
  return *this;
}*/