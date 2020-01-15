//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__SERVER_H_
#define MILESTONE2__SERVER_H_
#include "ClientHandler.h"
#include <netinet/in.h>

class Server {
  /*
 protected:
  ClientHandler* client_handler;
  int port;

 public:
  Server(ClientHandler* ch, int p) {
    this->client_handler = ch;
    this->port = p;
  }*/
  //virtual int open(int port, ClientHandler* ch) = 0;
  virtual int open(int port, ClientHandler* ch) = 0;
  virtual void stop() = 0;

};
#endif //MILESTONE2__SERVER_H_
