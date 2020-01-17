//
// Created by batel on 15/01/2020.
//

#include "SearchableSolver.h"

template <typename P, typename  S, typename T, typename SE>
SearchableSolver::SearchableSolver(Searcher<T> searcher) {
    this->searcher = searcher;
}
S SearchableSolver::solve(P problem) {
    // create searchable object from the problem
    Searchable searchable = new SE(problem);
    this->searcher.search(searchable);
}
