// FILE NAME: Task-Tracker                                                   **
// CREATOR: Godspower Government                                             **
// DATE: 12/15/2025                                                          **
// DESCRIPTION: This is a CLI Task-Tracker Program.                          **
//                                                                           **
// Copyright: Do not modify or make copy of this code without authorization  **
// ****************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// create a struct of task
struct Task {
    int id;
    string description;
    string status;
};
void saveTasksToFile(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i].id << "|"
            << tasks[i].description << "|"
            << tasks[i].status << endl;
    }
    file .close();
}

void loadTasksFromFile(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    string line;
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    while (getline(file, line)) {
        Task tempTask;
        int firstsep = line.find("|");
        int secondsep = line.find("|", firstsep + 1);

        tempTask.id = stoi(line.substr(0, firstsep));
        tempTask.description = line.substr(firstsep + 1, secondsep - firstsep - 1);
        tempTask.status = line.substr(secondsep + 1);
        tasks.push_back(tempTask);
    }
    file.close();
}

int main(int argc, char* argv[]){
    vector<Task> tasks;
  //  ofstream file("tasks.txt");
    loadTasksFromFile(tasks);

    if (argc < 2) {
        cout << "Usage format: <executabe> <command> [arguments] " << endl;
        return 0;
    }


    string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            cout << "Please give a description" << endl;
            return 0;
        }

        Task t1;
        t1.id = tasks.size() + 1;
        t1.description = argv[2];
        t1.status = "todo";
        tasks.push_back(t1);
        saveTasksToFile(tasks);

        cout << "Task added: (" <<t1.id <<") " << t1.description << endl;
    }
    else if (command == "list") {
        if (tasks.empty()) {
            cout << "No task found." << endl;
            return 0;
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout <<"[" << tasks[i].id << "] "
                << tasks[i].description << " ("
                << tasks[i].status << ")" << endl;
        }
    }
    else if (command == "mark-done") {
        if (argc < 3) {
            cout << "Please provide a task ID" << endl;
            return 0;
        }
        int id = stoi(argv[2]);
        bool found = false;

        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].id == id) {
                tasks[i].status = "done";
                saveTasksToFile(tasks);
                found = true;
                break;

            }
        }
        if (!found) {
            cout << "Task does not exist!" << endl;
        }else {
            cout << "Task mark done" << endl;
        }


    }
    else if (command == "delete") {
        if (argc < 3) {
            cout << "Please provide a task ID" << endl;
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].id == id) {
                tasks.erase(tasks.begin() + i);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Task does not exist!" << endl;
        }
        else {
            saveTasksToFile(tasks);
            cout << "Task deleted" << endl;
        }
    }


    return 0;
}

