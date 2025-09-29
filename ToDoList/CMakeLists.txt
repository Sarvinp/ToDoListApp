cmake_minimum_required(VERSION 3.26)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDoList main.cpp
        Task.cpp
        Observer.h
        TaskManager.cpp
        AutoSaveWorker.cpp)
