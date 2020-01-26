//
// Created by shaked on 16/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H
#include <unordered_map>
#include <list>
template <typename T>
class BFS : public ISearcher<T>{
    virtual vector<State<T>*> search(Searchable<T> *searchable) {
        vector<State<T>*> solution;
        list<State<T>*> open_list;
        unordered_map<State<T>*, bool> visited;
        State<T> *init = searchable->getInitialState();
        init->setPathCost(init->getCost());
        open_list.push_back(init);
        visited.insert({init, true});

        while (!open_list.empty()) {
            State<T> *state = open_list.front();
            open_list.pop_front();
            this->evaluated_nodes++;
            if (searchable->isGoalState(state)) {
                //back trace
                solution = this->backTrace(state, searchable);
                return solution;
            }
            vector<State<T>*> successors = searchable->getAllPossisbleStates(state);
            for (State<T>* s:successors) {
                if (s->getCost() != -1 && visited.find(s) == visited.end()) {
                    s->setCameFrom(state);
                    s->setPathCost(s->getCost() + state->getPathCost());
                    open_list.push_back(s);
                    visited.insert({s, true});
                }
            }
        }
        return solution;
    }
    virtual ISearcher<T>* deepCopy() {
        return new BFS();
    }
};

#endif //MILESTONE2_BFS_H
