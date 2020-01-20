#include "SerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReserver.h"
#include "Searcher.h"
#include "SearchableSolver.h"
#include "MatrixSearchable.h"
#include "State.h"
#include "Point.h"
#include "DFS.h"
#include "BFS.h"
#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {

  Searchable<Point*> *matrix = new MatrixSearchable("8,7,9\n2,3,1\n4,5,6\n0,0\n2,1\n");
  ISearcher<Point*>* s = new DFS<Point*>();
  vector<State<Point*>*> v =s->search(matrix);
  string a = matrix->getDirection(&v);

/*
>>>>>>> repairs
  //int port = stoi(argv[1]);
  CacheManager<string, string> *cache = new FileCacheManager(5);
  ISearcher<Point*> *algorithm = new DFS<Point*>;
  Solver<string, string> *solver = new SearchableSolver<string,string,Point*,MatrixSearchable>(algorithm);
  ClientHandler *clientHandler = new MyTestClientHandler<string,string>(cache, solver);
  server_side::Server *server = new SerialServer();
  server->open(5600, clientHandler);

  //server_side::boot::Main().main(argc ,argv);
*/
  return 0;
}