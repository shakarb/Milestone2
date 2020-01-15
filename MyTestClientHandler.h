//
// Created by shaked on 14/01/2020.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "StringReserver.h"

#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <algorithm>

class MyTestClientHandler : public ClientHandler {
private:
    FileCacheManager *cache;
    StringReserver *solver;
public:
    MyTestClientHandler(FileCacheManager *cache, StringReserver *solver);
    void handleClient(int client_socket);
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
