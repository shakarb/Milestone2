//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <list>
using namespace std;

template <typename T>
class Searchable {
public:
    virtual T getInitialState() = 0;
    //virtual bool isGoalState(T state) = 0;
    //virtual list<T> getAllPossisbleStates(T state) = 0;
};


#endif //MILESTONE2_SEARCHABLE_H
