//
// Created by nematpour on 9/29/2025.
//

#ifndef TODOLIST_AUTOSAVEWORKER_H
#define TODOLIST_AUTOSAVEWORKER_H


#pragma once
#include "Observer.h"
#include "TaskManager.h"
#include <thread>
#include <atomic>

class AutosaveWorker : public Observer {
public:
    AutosaveWorker(TaskManager& manager);
    ~AutosaveWorker();

    void onTaskChanged() override;

private:
    TaskManager& manager;
    std::thread worker;
    std::atomic<bool> running;
    void autosaveLoop();
};



#endif //TODOLIST_AUTOSAVEWORKER_H
