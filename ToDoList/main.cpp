
#include "TaskManager.h"
#include "AutosaveWorker.h"
#include <iostream>

int main() {
    TaskManager manager;
    AutosaveWorker autosaver(manager);

    std::string command;
    while (true) {
        std::cout << "\nCommands: add <desc>, start <id>, complete <id>, list, exit\n> ";
        std::getline(std::cin, command);

        if (command == "exit") break;
        else if (command.rfind("add ", 0) == 0) {
            manager.addTask(command.substr(4));
        } else if (command.rfind("complete ", 0) == 0) {
            int id = std::stoi(command.substr(9));
            manager.completeTask(id);
        } else if (command == "list") {
            manager.listTasks();
        }
        else if (command.rfind("start ", 0) == 0) {
            int id = std::stoi(command.substr(6));
            manager.startTask(id);
        }
        else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}
