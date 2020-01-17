//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__SERVER_H_
#define MILESTONE2__SERVER_H_
#include "FileCacheManager.h"
#include "StringReserver.h"
#include "MyTestClientHandler.h"
#include "SerialServer.h"
#include <netinet/in.h>

namespace server_side {
  class Server {
   public:
    //virtual int open(int port, ClientHandler* ch) = 0;
    virtual int open(int port, ClientHandler *ch) = 0;
    virtual void stop() = 0;

  };

  namespace boot {
    class Main {
     public:
      int main(int argc, char *argv[]) {
        //int port = stoi(argv[1]);

        CacheManager<string, string> *cache = new FileCacheManager(5);
        Solver<string, string> *solver = new StringReserver();
        ClientHandler *clientHandler = new MyTestClientHandler<string,string>(cache, solver);

        //Server *server = new
        //server->open(5600, clientHandler);

        return 0;
      }
    };
  }
}
#endif //MILESTONE2__SERVER_H_
