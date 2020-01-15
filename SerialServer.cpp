//
// Created by batel on 12/01/2020.
//
#include "SerialServer.h"

/*
 * Get new connections and handle them by passing them to a client handler
 */
int SerialServer::getClients(sockaddr_in address, int socketfd, ClientHandler *ch) {

    while(!this->isStop) {
        //accepting a client.
        socklen_t addrlen = sizeof(address);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);
        if(client_socket == -1) {
            cout<<"Client hasn't connected for 2 minutes"<<endl;
            return -4;
        } else {
            cout<<"Client is connected"<<endl;
        }
        ch->handleClient(client_socket);
        //close(client_socket);
    }

}

/*
 * Open a thread which listens to new clients
 */
int SerialServer::open(int port, ClientHandler *ch) {
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
    if(listen(socketfd, 1) == -1) {
        cout<<"Couldn't listen to socket"<<endl;
        return -3;
    } else{
        cout<<"Server is now listening ..."<<std::endl;
    }

    // define timout for client connecting
    struct timeval timeout;
    //timeout.tv_sec = 120000;
    timeout.tv_sec = 20;
    timeout.tv_usec = 0;

    // define timout for socket level
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    thread *openSever = new thread(&SerialServer::getClients, this, address, socketfd, ch);
    openSever->join();
    // checks if errno flag is on which means no data received within the expected time
    if(errno = EWOULDBLOCK) {
        this->stop();
        close(socketfd);
    }

}

/*
 * Stop getting clients
 */
void SerialServer::stop() {
    this->isStop = true;
}
