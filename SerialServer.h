//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__SERIALSERVER_H_
#define MILESTONE2__SERIALSERVER_H_
#include "Server.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <thread>

using namespace std;
using namespace server_side;

class SerialServer : public Server {
 private:
  volatile bool isStop = false;

 public:
  virtual int open(int port, ClientHandler *ch);
  int getClients(sockaddr_in address, int socketfd, ClientHandler *ch);
  virtual void stop();

};

#endif //MILESTONE2__SERIALSERVER_H_
