//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include "State.h"


class PriorityQueue {
public:
    template <typename T>
    struct compareCost {
        bool operator()(State<T> *s1,State<T> *s2) {
            return s2->getPathCost() < s1->getPathCost();
        }
    };

};


#endif //MILESTONE2_PRIORITYQUEUE_H
