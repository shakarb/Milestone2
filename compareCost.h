//
// Created by shaked on 22/01/2020.
//

#ifndef MILESTONE2_COMPARECOST_H
#define MILESTONE2_COMPARECOST_H

#include "State.h"

template <typename T>
struct compareCost {
    bool operator()(State<T> *s1,State<T> *s2) {
        return s2->getPathCost() < s1->getPathCost();
    }
};


#endif //MILESTONE2_COMPARECOST_H
