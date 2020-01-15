cmake_minimum_required(VERSION 3.15)
project(Milestone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Milestone2 main.cpp Server.h ClientHandler.h SerialServer.h SerialServer.cpp Solver.h
                CacheManager.h FileCacheManager.h MyClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h
                StringReserver.cpp StringReserver.h, ObjectAdapter.h, Searcher.h)
