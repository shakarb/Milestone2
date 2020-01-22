//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include "State.h"
#include "compareCost.h"
#include <queue>

template <typename T>
class PriorityQueue {
protected:

public:
    priority_queue<State<T>*, vector<State<T>*>, compareCost<T>> open_list;
    void reorderPriorityQueue() {
        priority_queue <State<T>*, vector<State<T>*>, compareCost<T>> tmp_open_list;
        while(!this->open_list.empty()) {
            tmp_open_list.push(this->open_list.top());
            this->open_list.pop();
        }
        this->open_list = tmp_open_list;
    }

    bool isInOpenList(State<T> *state) {
        priority_queue <State<T>*, vector<State<T>*>, compareCost<T>> tmp_open_list = this->open_list;
        while(!tmp_open_list.empty()) {
            State<T> *s = tmp_open_list.top();
            if(s->equals(state)) {
                return true;
            }
            tmp_open_list.pop();
        }
        return false;
    }

};


#endif //MILESTONE2_PRIORITYQUEUE_H
