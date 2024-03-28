#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task>& tasks, const string& description);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks, const string& description);
void removeTask(vector<Task>& tasks, const string& description);

int main() {
    vector<Task> tasks;

    char choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Remove Task\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                string taskDescription;
                cout << "Enter task description to mark as completed: ";
                cin.ignore();
                getline(cin, taskDescription);
                markTaskCompleted(tasks, taskDescription);
                break;
            }
            case '4': {
                string taskDescription;
                cout << "Enter task description to remove: ";
                cin.ignore();
                getline(cin, taskDescription);
                removeTask(tasks, taskDescription);
                break;
            }
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != '5');

    return 0;
}

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
    } else {
        cout << "Tasks:\n";
        for (const auto& task : tasks) {
            cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

void markTaskCompleted(vector<Task>& tasks, const string& description) {
    auto it = find_if(tasks.begin(), tasks.end(),
                      [&description](const Task& task) { return task.description == description; });
    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

void removeTask(vector<Task>& tasks, const string& description) {
    auto it = find_if(tasks.begin(), tasks.end(),
                      [&description](const Task& task) { return task.description == description; });
    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

