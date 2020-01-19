//
// Created by shaked on 19/01/2020.
//

#ifndef MILESTONE2_ISEARCHER_H
#define MILESTONE2_ISEARCHER_H

#include "Searchable.h"

template <typename S,typename T>
class ISearcher {
private:
    vector<State<T>> states;
    int evaluated_nodes;
public:
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual S search(Searchable<T> *s) = 0;
};


#endif //MILESTONE2_ISEARCHER_H
