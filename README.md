# Searching Algorithms Server
In this program a server gets from client different matrix problems and it handles them by running searching algorithms.\
The goal is to find the shortest way from given source to given destination.
The server supports both getting client by client or get clients in parallel and manages solution cache in an efficient way.

## The Supported Algorithms
**BFS**

**DFS**

**Best First Search**

**A-Star**

## Steps For Executing The Program
1. Compile the program by running the following command:
 ```
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
```
2. Run the program by running the following command: \
    **supply the port you want to use, otherwise the server will listen on port 5600 by default**
    ```
    ./a.out 5600
    ```
3. Open terminal and enter the following command : 
  ```
  telnet localhost 5600
  ```
4. Enter the matrix 
5. Enter init and goal points in two different lines
6. Enter "end" when you finished
7. Wait for answer from the server

[Git Link](https://github.com/shakarb/Milestone2)
