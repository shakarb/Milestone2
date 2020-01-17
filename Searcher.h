//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "Searchable.h"

template <typename T>
class Searcher {
public:
    // need to change to return solution and not void
    virtual void search(Searchable<T> s) = 0;
};

#endif //MILESTONE2__SEARCHER_H_
