//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"

template <typename S, typename T>
class BestFirstSearch : public Searcher<S,T>{
    virtual S search(Searchable<T> *searchable) {
        vector<State<T>> queue;
        map<State<T>, bool> visited;
        State<T> *init = searchable->getInitialState();
        queue.push_back(init);
        visited.insert(init, true);
    }
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
