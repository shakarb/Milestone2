//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__FILECACHEMANAGER_H_
#define MILESTONE2__FILECACHEMANAGER_H_
#include "CacheManager.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <fstream>
#include <functional>
#include <vector>
using namespace std;

class FileCacheManager : public CacheManager<string, string>{

  int capacity;
  unordered_map<string, bool> problems_with_solutions;
  unordered_map<string, list<pair<string,string>>::iterator> cacheMap;
  list<pair<string,string>> cacheList;

 public:
  FileCacheManager(int capa) {
    this ->capacity = capa;
  }

  void insert(string problem, string solution){
    // to this problem will be a solution so:
    this->problems_with_solutions[problem] = true;
    //if the problem isn't in the map.
    if(this->cacheMap.find(problem) == this->cacheMap.end()) {
      //if the cache is full
      if(this->capacity == (signed)this->cacheList.size()) {
        //delete least recently used element.
        pair<string,string> last = this->cacheList.back();
        //pops from the list.
        this->cacheList.pop_back();
        //delete from the map
        this->cacheMap.erase(last.first);
      }

      // the problem is - problem.to_string
      ofstream outFile(problem);
      if(!outFile) {
        //throw "cannot open file" + problem;
        cout<<"cannot open file" + problem<<endl;
      }
      outFile << solution;
      outFile.close();
      this->cacheList.push_front(pair<string, string>(problem,solution));
      this->cacheMap[problem] = this->cacheList.begin();
      //this->cacheMap.insert(problem,this->cacheList.begin());

    } else {
      // delete from the list
      this->cacheList.erase(this->cacheMap[problem]);
      // push to the front of the list:
      pair<string,string> updatePair(problem,solution);
      this->cacheList.push_front(updatePair);
      this->cacheMap[problem] = this->cacheList.begin();

      ofstream outFile(problem);
      if(!outFile) {
        //throw "cannot open file" + problem;
        cout<<"cannot open file" + problem<<endl;
      }
      outFile << solution;
      outFile.close();
    }
  }


  string get(string problem){
    //if the problem is in the cache
    if(this->cacheMap.find(problem)!= this->cacheMap.end()) {
      // save the object that we want return.
      auto cacheValue = this->cacheMap.find(problem)->second;
      //update him to be the most used.
      this->cacheList.erase(cacheValue);
      this->cacheList.push_front(pair<string, string>(cacheValue->first,cacheValue->second));
      return cacheValue->second;
    } else {

      std::ifstream inFile(problem);
      if(!inFile){
        //throw "an error";
        cout<<"cannot open file to read"<<endl;
      }
      std::string solution;
      std::getline(inFile, solution);

      pair<string,string> newPair(problem,solution);
      if(this->capacity == (signed)this->cacheList.size()){
        //delete least recently used element.
        pair<string,string> last = this->cacheList.back();
        //pops from the list.
        this->cacheList.pop_back();
        //delete from the map
        this->cacheMap.erase(last.first);
      }
      this->cacheList.push_front(newPair);
      this->cacheMap[problem] = this->cacheList.begin();
      return solution;
    }
  }
  void foreach(const function<void(string&)> func){
    for(pair<string,string> p : this->cacheList) {
      func(p.second);
    }
  }

  bool hasSolution(string problem) {
    //if the problem isn't has a solution.
    if(this->problems_with_solutions.find(problem) == this->problems_with_solutions.end()) {
      return false;
    }
    return true;
  }
};
#endif //MILESTONE2__FILECACHEMANAGER_H_
