//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "ISearcher.h"
#include "Searchable.h"
#include "State.h"

#include <vector>
#include <map>

template <typename S,typename T>
class Searcher : public ISearcher<S,T>{
private:
    vector<State<T>> states;
    int evaluated_nodes;
public:
    Searcher() {
        this->count_nodes = 0;
    }
protected:
    State<T> popState() {
        this->evaluated_nodes++;
        State<T> s = this->states.back();
        this->states.pop_back();
    }

};

#endif //MILESTONE2__SEARCHER_H_
