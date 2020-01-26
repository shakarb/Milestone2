//
// Created by batel on 22/01/2020.
//

#ifndef MILESTONE2__ASTAR_H_
#define MILESTONE2__ASTAR_H_
#include "PriorityQueueSearcher.h"
#include <unordered_map>
template <typename T>
class AStar : public PriorityQueueSearcher<T> {
 public:
  virtual vector<State<T>*> search(Searchable<T> *searchable) {
    map<State<T>*, bool> visited;
    State<T> *init = searchable->getInitialState();
    init->setPathCost(init->getCost());
    init->setCameFrom(NULL);
    init->setDistanceFromGoal(searchable->disFromGoal(init));
    this->open_list.push(init);

    while (!this->open_list.empty()) {
      State<T> *state = this->open_list.top();
      this->popState();
      visited.insert({state, true});
      if (searchable->isGoalState(state)) {
        // call back trace
        vector<State<T>*> solution = this->backTrace(state, searchable);
        return solution;
      }
      vector<State<T>*> successors = searchable->getAllPossisbleStates(state);
      for (State<T>* s:successors) {
        bool in_open_list = this->isInOpenList(s);
        if (s->getCost() != -1 && (visited.find(s) == visited.end()) && (!in_open_list)) {
          // update cameFrom member of s and push it to open_list
          s->setCameFrom(state);
          s->setDistanceFromGoal(state->getPathCost() + s->getCost() + searchable->disFromGoal(s));
          s->setPathCost(state->getPathCost() + s->getCost());
          this->open_list.push(s);
        } else if (visited.find(s) != visited.end()) {
          continue;
        } else { //if we got here that means s is in the open list
          if(s->getCost() != -1) {
            // if the new path is better than the current one update it
            if ( state->getPathCost() + s->getPathCost() + searchable->disFromGoal(s) <= s->getDistanceFromGoal())  {
              s->setDistanceFromGoal(state->getPathCost() + state->getPathCost() + searchable->disFromGoal(s));
              this->reorderPriorityQueue();
              s->setCameFrom(state);
            }
          }
        }
      }
    }
    vector<State<T>*> empty_vector;
    return empty_vector;
  }
    virtual PriorityQueueSearcher<T>* deepCopy() {
        return new AStar();
    }
};

#endif //MILESTONE2__ASTAR_H_
