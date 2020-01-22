//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "ISearcher.h"
#include "Searchable.h"
#include "State.h"
#include "PriorityQueue.h"
#include "compareCost.h"
#include <queue>
#include <vector>
#include <map>

template <typename T>
class Searcher : public ISearcher<T>{
 protected:
  //open list - priority queue.
  PriorityQueue<T> *pq = new PriorityQueue<T>;
  State<T>* popState() {
    this->evaluated_nodes++;
    //pop from priority queue.
  }

  public:
  int getOpenListSize() {
    // return the size of the prioruty queue
  }
  virtual vector<State<T>*> search(Searchable<T> *s) = 0;
};

#endif //MILESTONE2__SEARCHER_H_
