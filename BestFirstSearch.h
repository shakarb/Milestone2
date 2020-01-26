//
// Created by shaked on 20/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "PriorityQueueSearcher.h"

template <typename T>
class BestFirstSearch : public PriorityQueueSearcher<T>{
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        vector<State<T>*> solution;
        map<State<T>*, bool> visited;
        State<T> *init = searchable->getInitialState();
        init->setPathCost(init->getCost());
        init->setCameFrom(NULL);
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
            for (auto s:successors) {
                bool in_open_list = this->isInOpenList(s);
                if (s->getCost() != -1 && visited.find(s) == visited.end() && !in_open_list) {
                    // update cameFrom member of s and push it to open_list
                    s->setCameFrom(state);
                    s->setPathCost(s->getCost() + state->getPathCost());
                    this->open_list.push(s);
                } else {
                    // if the new path is better than the current one update it
                    if (s->getCost() + state->getPathCost() < s->getPathCost()) {
                        s->setCameFrom(state);
                        s->setPathCost(s->getCost() + state->getPathCost());
                        if (!in_open_list) {
                            this->open_list.push(s);
                        } else {
                            this->reorderPriorityQueue();
                        }
                    }
                }
            }
        }
        return solution;
    }

    virtual PriorityQueueSearcher<T>* deepCopy() {
        return new BestFirstSearch();
    }

};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
