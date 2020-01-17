//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__OBJECTADAPTER_H_
#define MILESTONE2__OBJECTADAPTER_H_

#include "Solver.h"
#include "Searcher.h"

template <typename P, typename  S, typename T, typename SE>
class SearchableSolver : public Solver<P,S> {
 protected:
  Searcher<S,T> searcher;
 public:
    SearchableSolver(Searcher<S,T> searcher);
    virtual S solve(P problem);
};
#endif //MILESTONE2__OBJECTADAPTER_H_
