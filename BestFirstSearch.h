//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "PriorityQueue.h"

template <typename T>
class BestFirstSearch : public Searcher<T>{
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        map<State<T>*, bool> visited;
        State<T> *init = searchable->getInitialState();
        init->setPathCost(0);
        init->setCameFrom(NULL);
        this->pq->pushToOpenList(init);
        //visited.insert({init, true});

        while (!this->pq->isEmpty()) {
            State<T> *state = this->pq->topOfOpenList();
            this->pq->popFromOpenList();
            visited.insert({state, true});
            //this->evaluatedNodes++;
            if (searchable->isGoalState(state)) {
                // call back trace
                vector<State<T>*> solution = this->backTrace(state, searchable);
                return solution;
            }
            vector<State<T>*> successors = searchable->getAllPossisbleStates(state);
            for (auto s:successors) {
                bool in_open_list = this->pq->isInOpenList(s);
                if (s->getCost() != -1 && visited.find(s) == visited.end() && !in_open_list) {
                    // update cameFrom member of s and push it to open_list
                    s->setCameFrom(state);
                    s->setPathCost(s->getCost() + state->getPathCost());
                    this->pq->pushToOpenList(s);
                } else {
                    if(s->getCost() != -1) {
                        // if the new path is better than the current one update it
                        if (s->getCost() + state->getPathCost() < s->getPathCost()) {
                            s->setCameFrom(state);
                            s->setPathCost(s->getCost() + state->getPathCost());
                            if (!in_open_list) {
                                this->pq->pushToOpenList(s);
                            } else {
                                this->pq->reorderPriorityQueue();

                            }
                        }
                    }

                }
            }
        }
        //return solution;
    }
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
