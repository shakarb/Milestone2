//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "PriorityQueue.h"
#include <queue>
template <typename T>
class BestFirstSearch : public Searcher<T>{
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        //priority_queue <State<T>*, vector<State<T>*>, PriorityQueue::compareCost<T>> open_list;
        PriorityQueue<T> *pq = new PriorityQueue<T>;
        map<State<T>*, bool> visited;
        State<T> *init = searchable->getInitialState();
        init->setPathCost(0);
        init->setCameFrom(NULL);
        pq->open_list.push(init);
        //visited.insert({init, true});

        while (!pq->open_list.empty()) {
            State<T> *state = pq->open_list.top();
            pq->open_list.pop();
            visited.insert({state, true});
            //this->evaluatedNodes++;
            if (searchable->isGoalState(state)) {
                // call back trace
                vector<State<T>*> solution = this->backTrace(state, searchable);
                return solution;
            }
            vector<State<T>*> successors = searchable->getAllPossisbleStates(state);
            for (auto s:successors) {
                bool in_open_list = pq->isInOpenList(s);
                if (s->getCost() != -1 && visited.find(s) == visited.end() && !in_open_list) {
                    // update cameFrom member of s and push it to open_list
                    s->setCameFrom(state);
                    s->setPathCost(s->getCost() + state->getPathCost());
                    pq->open_list.push(s);
                } else {
                    if(s->getCost() != -1) {
                        // if the new path is better than the current one update it
                        if (s->getCost() + state->getPathCost() < s->getPathCost()) {
                            s->setCameFrom(state);
                            s->setPathCost(s->getCost() + state->getPathCost());
                            if (!in_open_list) {
                                pq->open_list.push(s);
                            } else {
                                pq->reorderPriorityQueue();

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
