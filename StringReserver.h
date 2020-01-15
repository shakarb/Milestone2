//
// Created by shaked on 14/01/2020.
//

#ifndef MILESTONE2_STRINGRESERVER_H
#define MILESTONE2_STRINGRESERVER_H

#include "Solver.h"

using namespace std;
class StringReserver : public Solver<string,string> {
public:
    virtual string solve(string problem);
};


#endif //MILESTONE2_STRINGRESERVER_H
