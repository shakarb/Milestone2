//
// Created by shaked on 14/01/2020.
//

#include "StringReserver.h"
string StringReserver::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}