//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <vector>
#include "State.h"
using namespace std;

template <typename T>
class Searchable {
public:
    //T getInitialState() {};
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual vector<State<T>*> getAllPossisbleStates(State<T>* state) = 0;
    virtual string getDirection(vector<State<T>*> backTrace);
};


#endif //MILESTONE2_SEARCHABLE_H
