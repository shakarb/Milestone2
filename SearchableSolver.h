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
    SearchableSolver(Searcher<S,T> searcher) {
        this->searcher = searcher;
    }
    S solve(P problem) {
        // create searchable object from the problem
        Searchable<T> searchable = new SE(problem);
        this->searcher.search(searchable);
    }
};
#endif //MILESTONE2__OBJECTADAPTER_H_
