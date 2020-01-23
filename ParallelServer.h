//
// Created by shaked on 22/01/2020.
//

#ifndef MILESTONE2_PARALLELSERVER_H
#define MILESTONE2_PARALLELSERVER_H

#include "Server.h"

using namespace server_side;
class ParallelServer : public Server {
private:
    volatile bool isStop = false;
public:
    virtual int open(int port, ClientHandler *ch);
    int getClients(sockaddr_in address, int socketfd, ClientHandler *ch);
    void handleClient(ClientHandler *ch, int client_socket);
    virtual void stop();

};


#endif //MILESTONE2_PARALLELSERVER_H
