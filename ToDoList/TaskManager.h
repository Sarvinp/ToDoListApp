//
// Created by nematpour on 9/29/2025.
//

#ifndef TODOLIST_TASKMANAGER_H
#define TODOLIST_TASKMANAGER_H


#pragma once
#include "Task.h"
#include "Observer.h"
#include <vector>
#include <memory>
#include <mutex>

class TaskManager {
public:
    void addTask(const std::string& description);
    void completeTask(int id);
    void listTasks() const;
    void registerObserver(Observer* obs);
    static  std::string statusSymbol(TaskStatus status);
    std::vector<Task> getTasksSnapshot() const;
    void startTask(int id); // mark as InProgress


private:
    std::vector<Task> tasks;
    std::vector<Observer*> observers;
    mutable std::mutex mutex;

    void notifyObservers();
};


#endif //TODOLIST_TASKMANAGER_H
