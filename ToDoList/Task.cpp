//
// Created by nematpour on 9/29/2025.
//

#include "Task.h"

Task::Task(int id, const std::string& description)
        : id(id), description(description),  status(TaskStatus::NotStarted) {}

int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
void Task::markInProgress() { status = TaskStatus::InProgress; }

void Task::markCompleted() { status = TaskStatus::Completed; }
TaskStatus Task::getStatus() const{
    return status;
}