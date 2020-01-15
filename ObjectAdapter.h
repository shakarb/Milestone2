//
// Created by batel on 15/01/2020.
//

#ifndef MILESTONE2__OBJECTADAPTER_H_
#define MILESTONE2__OBJECTADAPTER_H_
#include "Solver.h"
#include "Searcher.h"
template <typename P, typename  S>
class ObjectAdapter : public Solver<P,S> {
 protected:
  //Searcher<T>
 public:
  virtual S solve(P problem);
};
#endif //MILESTONE2__OBJECTADAPTER_H_
