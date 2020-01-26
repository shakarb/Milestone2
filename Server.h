//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__SERVER_H_
#define MILESTONE2__SERVER_H_
#include "FileCacheManager.h"
#include "StringReserver.h"
#include "MyTestClientHandler.h"
#include <netinet/in.h>

namespace server_side {
  class Server {
   public:
    virtual int open(int port, ClientHandler *ch) = 0;
  };
}
#endif //MILESTONE2__SERVER_H_
