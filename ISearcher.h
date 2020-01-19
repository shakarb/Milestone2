//
// Created by shaked on 19/01/2020.
//

#ifndef MILESTONE2_ISEARCHER_H
#define MILESTONE2_ISEARCHER_H

#include "Searchable.h"

template <typename S,typename T>
class ISearcher {
protected:
    int evaluated_nodes; // the modify is or in searchable either in the specific algorithms.
public:
    ISearcher() {
      this->evaluated_nodes = 0;
    }
    int getNumberOfNodesEvaluated() {
        return this->evaluated_nodes;
    }
    virtual S search(Searchable<T> *s) = 0;
    string backTrace(State<T>* current, Searchable<T>* searchable) {

    }
};


#endif //MILESTONE2_ISEARCHER_H
