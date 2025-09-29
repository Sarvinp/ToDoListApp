//
// Created by nematpour on 9/29/2025.
//

#include "TaskManager.h"
#include <iostream>

// Optional: move this into TaskManager as a static method or utility namespace
std::string TaskManager::statusSymbol(TaskStatus status) {
    switch (status) {
        case TaskStatus::Completed: return "[✔] ";
        case TaskStatus::InProgress: return "[~] ";
        case TaskStatus::NotStarted: return "[ ] ";
        default: return "[?] ";
    }
}

void TaskManager::addTask(const std::string& description) {
    std::lock_guard<std::mutex> lock(mutex);
    tasks.emplace_back(tasks.size() + 1, description);
    notifyObservers();
}

void TaskManager::completeTask(int id) {
    std::lock_guard<std::mutex> lock(mutex);
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            notifyObservers();
            return;
        }
    }
}

void TaskManager::listTasks() const {
    std::lock_guard<std::mutex> lock(mutex);
    for (const auto& task : tasks) {
        std::cout << "[" << task.getId() << "] "
                  << TaskManager::statusSymbol(task.getStatus())
                  << task.getDescription() << "\n";
    }
}

void TaskManager::registerObserver(Observer* obs) {
    observers.push_back(obs);
}

void TaskManager::notifyObservers() {
    for (auto* obs : observers) {
        obs->onTaskChanged();
    }
}
void TaskManager::startTask(int id) {
    std::lock_guard<std::mutex> lock(mutex);
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markInProgress();
            notifyObservers();
            return;
        }
    }
}

std::vector<Task> TaskManager::getTasksSnapshot() const {
    std::lock_guard<std::mutex> lock(mutex);
    return tasks;
}
