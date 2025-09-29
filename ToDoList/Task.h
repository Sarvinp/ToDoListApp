//
// Created by nematpour on 9/29/2025.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H


#pragma once
#include <string>
enum class TaskStatus {
    NotStarted,
    InProgress,
    Completed
};

class Task {
public:
    Task(int id, const std::string& description);
    int getId() const;
    std::string getDescription() const;
    void markCompleted();
    void markInProgress();
    TaskStatus getStatus() const;
private:
    int id;
    std::string description;
    TaskStatus status;
};


#endif //TODOLIST_TASK_H
