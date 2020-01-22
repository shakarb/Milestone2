//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template <typename T>
class State {
private:
   T state;
   double cost;
   double path_cost;
   double distance_from_goal;
   State<T>* came_from;
public:
    State(T s) {
      this->state = s;
      this->distance_from_goal = 0;
    }
    // work only in the cases that T is an address of something
    bool equals(State<T>* state_obj) {

      if(*this->state == *state_obj->state) {
          return true;
      }
      return false;
    }

    void setCost(double c) {
      this->cost = c;
    }

    double getCost() {
      return this->cost;
    }

    void setCameFrom(State<T>* cf) {
      this->came_from = cf;
    }

    State<T>* getCameFrom() {
      return this->came_from;
    }

    T getState() {
      return this->state;
    }

    void setPathCost(double pc) {
        this->path_cost = pc;
    }

    double getPathCost() {
        return this->path_cost;
    }

    void setDistanceFromGoal(double d) {
      this->distance_from_goal = d;
    }

    double getDistanceFromGoal() {
      return this->distance_from_goal;
    }

};


#endif //MILESTONE2_STATE_H
