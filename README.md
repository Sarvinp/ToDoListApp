# 📝 ToDoListApp

A modular, multithreaded command-line To-Do List application written in C++. Designed for clarity, extensibility, and professional polish.

## 🚀 Features

- ✅ Add, start, and complete tasks
- 🔁 Autosave every 5 seconds (background thread)
- 🔔 Observer pattern for reactive updates
- 🧵 Thread-safe task management
- 📄 Status indicators: `[ ]` Not Started, `[~]` In Progress, `[✔]` Completed

## 🧱 Architecture

- `Task`: Represents a single to-do item
- `TaskManager`: Manages task lifecycle and observers
- `AutosaveWorker`: Background thread that saves tasks to `autosave.txt`
- `Observer`: Interface for reactive components

## 🛠️ Build Instructions

```bash
git clone https://github.com/YOUR_USERNAME/ToDoListApp.git
cd ToDoListApp
mkdir build && cd build
cmake ..
make
./todo
```


Requires CMake and a C++17-compatible compiler

## 📦 Commands
add <description> — Add a new task

start <id> — Mark task as In Progress

complete <id> — Mark task as Completed

list — Show all tasks

exit — Quit the app


## 📁 Autosave Format
Saved to autosave.txt every 5 seconds:
<id>,<status>,<description>
### Example:
1,Completed,Submit report

2,InProgress,Write documentation

## 🧠 Future Enhancements

Priority levels

Due dates
