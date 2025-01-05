#include <iostream>
#include <string>
#include <vector>

class Task {
private:
    std::string name;
    std::string dueDate;

public:
    Task(const std::string& taskName, const std::string& taskDueDate)
        : name(taskName), dueDate(taskDueDate) {}

    void setTaskName(const std::string& taskName) {
        name = taskName;
    }

    void setTaskDueDate(const std::string& taskDueDate) {
        dueDate = taskDueDate;
    }

    std::string getTaskName() const {
        return name;
    }

    std::string getTaskDueDate() const {
        return dueDate;
    }

    void displayTask() const {
        std::cout << "Task: " << name << ", Due Date: " << dueDate << "\n";
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask() {
        std::string taskName, taskDueDate;
        std::cout << "Enter task name: ";
        std::getline(std::cin, taskName);
        std::cout << "Enter task due date: ";
        std::getline(std::cin, taskDueDate);

        tasks.emplace_back(taskName, taskDueDate);
        std::cout << "Task added successfully!\n";
    }

    void removeTask() {
        if (tasks.empty()) {
            std::cout << "No tasks to remove.\n";
            return;
        }

        viewTasks();
        int index;
        std::cout << "Enter the task number to remove: ";
        std::cin >> index;
        std::cin.ignore(); // To handle leftover newline character

        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + (index - 1));
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks to display.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. View Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To handle leftover newline character

        switch (choice) {
        case 1:
            todoList.addTask();
            break;
        case 2:
            todoList.removeTask();
            break;
        case 3:
            todoList.viewTasks();
            break;
        case 4:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
