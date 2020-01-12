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
#include <sstream>
#include <thread>
//#include <stdlib.h> // atoi
#include <mutex>
using namespace std;

class SerialServer : Server{

  virtual int open(int port, ClientHandler* ch);
};
#endif //MILESTONE2__SERIALSERVER_H_
