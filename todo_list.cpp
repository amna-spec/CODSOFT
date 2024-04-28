#include <iostream>
#include <vector>
#include <string>

using namespace std;

class task {
private:
    string description;
    bool completed;
public:
    task(string description, bool completed = false) : description(description), completed(completed) 
{

}
    void markCompleted() 
    {
        completed = true;
    }

    string getDescription()
    {
        return description;
    }

    bool isCompleted()  
    {
        return completed;
    }

};


class todolist 
{
private:
    vector<task> tasks;
public:
 
    void addtask(const string& description)
     {
        tasks.push_back(task(description));
        cout << "Task added successfully!" << endl;
    }

 
    void viewTasks()  {
        if (tasks.empty()) {
            cout << "Your to-do list is empty." << endl;
        } else {
            cout << "Your To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i+1 << ". " << tasks[i].getDescription() << " - ";
                if (tasks[i].isCompleted()) {
                    cout << "Completed" << endl;
                } else {
                    cout << "Pending" << endl;
                }
            }
        }
    }

    void markTaskCompleted(size_t index) 
    {
        if (index >= 1 && index <= tasks.size()) 
        {
            tasks[index - 1].markCompleted();
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }

  
    void removeTask(size_t index) 
    {
        if (index >= 1 && index <= tasks.size()) 
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully." << endl;
        } else 
        {
            cout << "Invalid task number. Please try again." << endl;
        }
    }


};

int main() 
  {
    todolist todolist1;
    int choice;
    string taskDescription;

 while (true) {
    cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Quit!\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter the task description: ";
        cin.ignore(); 
        getline(cin, taskDescription);
        todolist1.addtask(taskDescription);
            break;
    case 2:
        todolist1.viewTasks();
            break;
    case 3:
        size_t index;
         cout << "Enter the task number to mark as completed: ";
        cin >> index;
        todolist1.markTaskCompleted(index);
            break;
    case 4:
        cout << "Enter the task number to remove: ";
        cin >> index;
        todolist1.removeTask(index);
            break;
    case 5:
        cout << "Exiting..." << endl;
                return 0;
     default:
                cout << "Invalid choice.Try again please." << endl;
        }
    }

    return 0;
  }
