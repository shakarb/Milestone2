//
// Created by batel on 12/01/2020.
//
#include "SerialServer.h"

int SerialServer::open(int port, ClientHandler *ch) {
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
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
  //accepting a client.
  socklen_t addrlen = sizeof(address);
  int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);
  if(client_socket == -1) {
    cout<<"Couldn't accept a client"<<endl;
    return -4;
  }
  close(socketfd);
}
