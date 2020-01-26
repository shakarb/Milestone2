//
// Created by shaked on 22/01/2020.
//

#include "ParallelServer.h"

/*
 * Get new connections and handle them by passing them to a client handler
 */

int ParallelServer::getClients(sockaddr_in address, int socketfd, ClientHandler *ch) {
    while(!this->isStop) {
        //accepting a client.
        socklen_t addrlen = sizeof(address);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);
        if(client_socket == -1) {
            cout<<"Client hasn't connected for 2 minutes"<<endl;
            this->stop();
        } else {
            cout<<"Client is connected"<<endl;
            thread *handle = new thread(&ParallelServer::handleClient, this, ch, client_socket);
            handle->detach();
        }

    }
}

int ParallelServer ::open(int port, ClientHandler *ch) {
    int socketfd;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1) {
        cout<< "couldn't create a socket"<<endl;
        return -1;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(socketfd,(struct sockaddr*)&address, sizeof(address)) == -1) {
        cout<<"Couldn't bind a socket"<<endl;
        return -2;
    }
    if(listen(socketfd, 10) == -1) {
        cout<<"Couldn't listen to socket"<<endl;
        return -3;
    } else{
        cout<<"Server is now listening ..."<<std::endl;
    }

    // define timout for client connecting
    struct timeval timeout;
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;

    // define timout for socket level
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    thread *openSever = new thread(&ParallelServer::getClients, this, address, socketfd, ch);
    openSever->join();
    /*
    while(!this->isStop) {
        //accepting a client.
        socklen_t addrlen = sizeof(address);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);
        if(client_socket == -1) {
            cout<<"Client hasn't connected for 2 minutes"<<endl;
            this->stop();
        } else {
            cout<<"Client is connected"<<endl;
            thread *handle = new thread(&ParallelServer::handleClient, this, ch, client_socket);
            handle->detach();
        }

    }*/
}

/*
 * Handle every client in a different thread.
 */
void ParallelServer::handleClient(ClientHandler *ch, int client_socket) {
    ClientHandler *newCh = ch->deepCopy();
    newCh->handleClient(client_socket);
    //ch->handleClient(client_socket);
}

/*
* Stop getting clients
*/
void ParallelServer::stop() {
    this->isStop = true;
}