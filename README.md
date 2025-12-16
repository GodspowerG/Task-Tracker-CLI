# Task Tracker CLI (C++)

A simple command-line task tracker application built in C++.  
This project allows users to create, view, update, and delete tasks directly from the terminal, with tasks saved to a file so they persist between program runs.

##  Features
- Add new tasks from the command line
- List all existing tasks
- Mark tasks as completed
- Delete tasks by ID
- Persistent storage using a text file
- Simple and readable command-line interface


## Technologies Used
- **C++**
- Standard Library (`iostream`, `vector`, `string`, `fstream`)
- File I/O for persistence
- Command-line arguments (`argc`, `argv`)
- Built using CMake (CLion compatible)

> Note: Compiled binaries and runtime data files are intentionally ignored.

## How It Works
- Each task is represented using a `Task` structure containing:
  - `id`
  - `description`
  - `status`
- Tasks are stored in a `vector<Task>` while the program runs.
- Tasks are saved to a text file (`tasks.txt`) using a delimiter-based format:

- When the program starts, tasks are loaded from the file into memory.
- Any changes (add, delete, update) are written back to the file.


## ▶️ Usage

Compile the program:

```bash
g++ main.cpp -o task
