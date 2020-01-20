//
// Created by shaked on 16/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H
#include "Searcher.h"
/*
template <typename T>
class BFS : public ISearcher<T>{
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        vector<State<T>*> queue;
        map<State<T>*, bool> visited;
        State<T> *prev = searchable->getInitialState();
        queue.push_back(prev);
        visited.insert(prev, true);

        while (!queue.empty()) {
            State<T> *state = queue.front();
            queue.pop_back();
            this->evaluatedNodes++;
            if (searchable->isGoalState(state)) {
                //back trace
                vector<State<T>*> solution = this->backTrace(state, searchable);
                return solution;
            }
            vector<State<Point *>> successors = searchable->getAllPossisbleStates(state);
            for (auto s:successors) {
                s.setCameFrom(state);
                if (s.getCost() != -1 && visited.find(s) == visited.end()) {
                    queue.push_back(s);
                    visited.insert(s, true);
                }
            }

        }
        return "Couldn't find a solution";
    }
};
*/
#endif //MILESTONE2_BFS_H
