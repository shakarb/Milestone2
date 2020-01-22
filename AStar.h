//
// Created by batel on 22/01/2020.
//

#ifndef MILESTONE2__ASTAR_H_
#define MILESTONE2__ASTAR_H_
#include "Searcher.h"
#include <unordered_map>
template <typename T>
class AStar : public Searcher<T> {
 public:
  vector<State<T>*> search(Searchable<T> *s) {
    unordered_map<State<T> *, bool> visited;
  }
};

#endif //MILESTONE2__ASTAR_H_
