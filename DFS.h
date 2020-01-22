//
// Created by batel on 19/01/2020.
//

#ifndef MILESTONE2__DFS_H_
#define MILESTONE2__DFS_H_
#include "ISearcher.h"
#include <unordered_map>
#include <stack>
////////////////need to sum the costs.
template <typename T>
class DFS: public ISearcher<T> {
 public:
  vector<State<T>*> search(Searchable<T> *s) {
    unordered_map<State<T>*, bool> visited;
    stack<State<T>*> stack;
    int cost_sum = 0;
    State<T>* init_state = s->getInitialState();
    int has_neighbors = 0;
    // initialize for the beginning of the algorithm running.
    stack.push(init_state);
    visited.insert({init_state, true});

    while(!stack.empty()) {
      State<T>* top_state = stack.top();
      cost_sum+=top_state->getCost();
      this->evaluated_nodes++;
      if(s->isGoalState(top_state)) {
        vector<State<T>*> solution = this->backTrace(top_state, s);
        return solution;
      }
      vector<State<T>*> neighbors = s->getAllPossisbleStates(top_state);
      for(int i = 0; i < neighbors.size(); i++){
        State<T>* neighbor = neighbors[i];
        // update, insert to the stack and to visited map only the first neighbor we see.
        if((neighbor->getCost() != -1) && (visited.find(neighbor) == visited.end())){
          has_neighbors = 1;
          neighbor->setCameFrom(top_state);
          stack.push(neighbor);
          visited.insert({neighbor, true});
          break;
        }
      }
      if(has_neighbors == 0) {
        stack.pop();
        // to count only one 'top' in a neighbor
        this->evaluated_nodes--;
      }
      has_neighbors = 0;
    }
    vector<State<T>*> empty_vector;
    return empty_vector;
  }

};

#endif //MILESTONE2__DFS_H_
