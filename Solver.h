//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__SOLVER_H_
#define MILESTONE2__SOLVER_H_

#include <string>
#include <bits/stdtr1c++.h>

template <typename P, typename  S>
class Solver {
 public:
  virtual S solve(P problem) = 0;
};

#endif //MILESTONE2__SOLVER_H_
