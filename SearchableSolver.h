//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__OBJECTADAPTER_H_
#define MILESTONE2__OBJECTADAPTER_H_

#include "Solver.h"
#include "Searchable.h"
#include "ISearcher.h"

template <typename P, typename  S, typename T, typename SE>
class SearchableSolver : public Solver<P,S> {
 protected:
  ISearcher<T> *searcher;
 public:
    SearchableSolver(ISearcher<T> *searcher) {
        this->searcher = searcher;
    }
    // problem should be a string, and every constructor of searchable should accept a string.
    S solve(P problem) {
        // create searchable object from the problem
        Searchable<T> *searchable = new SE(problem);
        vector<State<T>*> trace = this->searcher->search(searchable);
        searchable->getInitialState();
        return searchable->getDirection(&trace);
    }

    SearchableSolver<P,S,T,SE> *deepCopy() {
        return new SearchableSolver<P,S,T,SE>(searcher->deepCopy());
    }
};
#endif //MILESTONE2__OBJECTADAPTER_H_
