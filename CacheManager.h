//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__CACHEMANAGER_H_
#define MILESTONE2__CACHEMANAGER_H_
#include<string>
#include<functional>
using namespace std;
// an interface
template <typename P, typename  S>
class CacheManager {
 public:
  virtual void insert(P problem, S solution) = 0;
  virtual S get(P problem) = 0;
  virtual void foreach(const function<void(S&)> func) = 0;
  virtual bool hasSolution(P problem) = 0;
};
#endif //MILESTONE2__CACHEMANAGER_H_
