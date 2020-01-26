#include "SerialServer.h"
#include "ParallelServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReserver.h"
#include "SearchableSolver.h"
#include "MatrixSearchable.h"
#include "State.h"
#include "Point.h"
#include "DFS.h"
#include "BFS.h"
#include "PriorityQueueSearcher.h"
#include "BestFirstSearch.h"

#include "AStar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
    int port;
    if(argc == 2) {
        port = stoi(argv[1]);
    } else {
        port = 5600;
    }
    CacheManager<string, string> *cache = new FileCacheManager(5);
    ISearcher<Point*> *algorithm = new AStar<Point*>;
    Solver<string, string> *solver = new SearchableSolver<string,string,Point*,MatrixSearchable>(algorithm);
    ClientHandler *clientHandler = new MyTestClientHandler<string,string>(cache, solver);
    server_side::Server *server = new ParallelServer();
    //server_side::Server *server = new SerialServer();
    server->open(port, clientHandler);

  //server_side::boot::Main().main(argc ,argv);
  return 0;
};