//
// Created by shaked on 14/01/2020.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "StringReserver.h"
#include "SearchableSolver.h"

#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <algorithm>
#include <mutex>
template <typename P, typename  S>
class MyTestClientHandler : public ClientHandler {
private:
    CacheManager<P,S> *cache;
    Solver<P,S> *solver;
public:
    MyTestClientHandler(CacheManager<P,S> *cm, Solver<P,S> *s) {
      this->cache = cm;
      this->solver = s;
    }

    ClientHandler* deepCopy() {
        ClientHandler *clientHandler = new MyTestClientHandler<string,string>(this->cache, this->solver->deepCopy());
        return clientHandler;
    }

    void handleClient(int client_socket) {
        mutex mtx;
        char ch;
        string solution, line = "", data = "";
        while (line != "end") {
            read(client_socket, &ch, 1);
            line.append(1, ch);
            if (line == "end") {
                cout << "Client finished the session" << endl;
            }
            if (ch == '\n') {
                data = data + line;
                line = "";
            }
        }
        // remove the spaces from the expression_string string.
        data.erase(remove(data.begin(), data.end(), ' '), data.end());
        if (this->cache->hasSolution(data)) {
            //cout<<"get"<<endl;
            solution = this->cache->get(data);
        } else {
            //cout<<"insert"<<endl;
            //mtx.lock();
            solution = solver->solve(data);
            //mtx.unlock();
            this->cache->insert(data, solution);
        }
        // Prepare solution for sending it to the client
        char solution_msg[solution.length() + 1];
        strcpy(solution_msg, solution.c_str());

        int is_sent = send(client_socket, solution_msg, strlen(solution_msg), 0);
        if (is_sent == -1) {
            cout << "Couldn't send data to client" << endl;
        }
    }
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
