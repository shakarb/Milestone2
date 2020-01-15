//
// Created by shaked on 14/01/2020.
//

#include "MyTestClientHandler.h"

using namespace std;

MyTestClientHandler::MyTestClientHandler(FileCacheManager *cache, StringReserver *solver) {
    this->cache = cache;
    this->solver = solver;
}

void MyTestClientHandler::handleClient(int client_socket) {
    char ch;
    string solution, line = "";
    while(line != "end") {
        read(client_socket, &ch, 1);
        if (ch == '\n') {
            // check if the problem has a solution - if so, get it from cache
            // else - solve the problem
            if (this->cache->hasSolution(line)) {
                solution = this->cache->get(line);
            } else {
                solution = this->solver->solve(line);
                this->cache->insert(line, solution);
            }
            // Prepare solution for sending it to the client
            solution.append("\r\n");
            char solution_msg[solution.length() + 1];
            strcpy(solution_msg, solution.c_str());

            int is_sent = send(client_socket, solution_msg, strlen(solution_msg), 0);
            if (is_sent == -1) {
                cout << "Couldn't send data to client" << endl;
            }
            line = "";
        } else {
            line.append(1, ch);
        }
        if (line == "end") {
            cout<<"Client finished the session"<<endl;
            close(client_socket);
        }


    }
}