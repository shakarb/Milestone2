//
// Created by batel on 12/01/2020.
//

#ifndef MILESTONE2__CLIENTHANDLER_H_
#define MILESTONE2__CLIENTHANDLER_H_

class ClientHandler {
public:
  virtual void handleClient(int client_socket) = 0;
};
#endif //MILESTONE2__CLIENTHANDLER_H_
