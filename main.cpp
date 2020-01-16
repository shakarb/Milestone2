#include "SerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReserver.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
    //int port = stoi(argv[1]);

    CacheManager<string, string> *cache = new FileCacheManager(5);
    Solver<string, string> *solver = new StringReserver();
    ClientHandler *clientHandler = new MyTestClientHandler<string,string>(cache, solver);
    server_side::Server *server = new SerialServer();
    server->open(5600, clientHandler);
    //server_side::boot::Main().main(argc ,argv);


    return 0;
}