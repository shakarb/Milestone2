//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "Searchable.h"

template <typename S,typename T>
class Searcher {
public:
    virtual S search(Searchable<T> s) = 0;
};

#endif //MILESTONE2__SEARCHER_H_
