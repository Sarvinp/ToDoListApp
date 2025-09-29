//
// Created by nematpour on 9/29/2025.
//

#include "AutoSaveWorker.h"
#include <fstream>
#include <chrono>

AutosaveWorker::AutosaveWorker(TaskManager& manager)
        : manager(manager), running(true) {
    manager.registerObserver(this);
    worker = std::thread(&AutosaveWorker::autosaveLoop, this);
}

AutosaveWorker::~AutosaveWorker() {
    running = false;
    if (worker.joinable()) worker.join();
}

void AutosaveWorker::onTaskChanged() {
    // Triggered when tasks change
}

void AutosaveWorker::autosaveLoop() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        auto snapshot = manager.getTasksSnapshot();
        std::ofstream out("autosave.txt");
        for (const auto& task : snapshot) {
            std::string statusText;
            switch (task.getStatus()) {
                case TaskStatus::NotStarted: statusText = "NotStarted"; break;
                case TaskStatus::InProgress: statusText = "InProgress"; break;
                case TaskStatus::Completed:  statusText = "Completed";  break;
            }

            out << task.getId() << "," << statusText << "," << task.getDescription() << "\n";

//            out << task.getId() << "," << static_cast<int>(task.getStatus()) << "," << task.getDescription() << "\n";
        }
    }
}
