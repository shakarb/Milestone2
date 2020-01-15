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
    FileCacheManager *cache = new FileCacheManager(5);
    StringReserver *solver = new StringReserver();
    MyTestClientHandler *clientHandler = new MyTestClientHandler(cache, solver);
    SerialServer *server = new SerialServer();
    //server->open(port, clientHandler);
    //server->open(5600, clientHandler);
    server->open(5600, clientHandler);



    //string s = "aba";
    //cout<<s.c_str()<<endl;
    /*
    std::ofstream file("filename");
    std::string my_string = "Hello text in file\n";
    file << my_string;*/
    return 0;
}