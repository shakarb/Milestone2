//
// Created by shaked on 19/01/2020.
//

#ifndef MILESTONE2_ISEARCHER_H
#define MILESTONE2_ISEARCHER_H

#include "Searchable.h"
#include "State.h"
#include <unordered_map>
#include <string>

template <typename T>
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
    virtual vector<State<T>*>search(Searchable<T> *s) = 0;

    vector<State<T>*> backTrace(State<T>* current, Searchable<T>* searchable) {
      vector<State<T>*> trace;
      while(current->getState()!= searchable->getInitialState()->getState()){
        trace.push_back(current);
        current = current->getCameFrom();
      }
      trace.push_back(searchable->getInitialState());
      return trace;
    }
};


#endif //MILESTONE2_ISEARCHER_H
