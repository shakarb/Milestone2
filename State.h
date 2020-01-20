//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template <typename T>
class State {
private:
   T state;
   int cost;
   int best_cost;
   State<T>* came_from;
public:
    State(T s) {
      this->state = s;
    }
    // work only in the cases that T is an address of something
    bool equals(State<T>* state_obj) {

      if(*this->state == *state_obj->state) {
          return true;
      }
      return false;
    }

    void setCost(int c) {
      this->cost = c;
    }

    int getCost() {
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

    void setBestCost(int bc) {
        this->best_cost = bc;
    }

    int getBestCost() {
        return this->best_cost;
    }
};


#endif //MILESTONE2_STATE_H
