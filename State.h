//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template <typename T>
class State {
    T state;
    // double cost;
    // State<T> came_from;
public:
    State(T s) {
        this->state = s;
    }
    bool equals(State<T> state_obj) {
        if(this->state == state_obj.state) {
            return true;
        }
        return false;
    }
};


#endif //MILESTONE2_STATE_H
