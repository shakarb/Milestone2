//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <vector>
#include <string>
#include "State.h"
#include <string>
using namespace std;

template <typename T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual vector<State<T>*> getAllPossisbleStates(State<T>* state) = 0;
    virtual string getDirection(vector<State<T>*> *trace) = 0;
    //virtual double disFromGoal(State<T>* state) = 0 ;
};


#endif //MILESTONE2_SEARCHABLE_H
