#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using String = std::string;

//  @brief Task object that represents a task, and will include a title, description, and a time.
//  @param name  name of the task.
//  @param description  description of the task
//  @param priorty_rating priority of the task. 
class Task{
    public:
    Task(const std::string& taskName = "Default", const std::string& taskDescrip = "Default", const int priority_rating = 0){
        taskN = taskName;
        taskD = taskDescrip;
        priority = priority_rating;
    }
    //  @brief returns the reference of task name.
    std::string& getTaskName(){
        return taskN;
    }
    //  @brief returns the referenceo of task description.
    std::string& getTaskDescription(){
        return taskD;
    }
    //  @brief returns the priorty rating of the task.
    int& getPriorityRating(){
        return priority;
    }
    private:
        std::string taskN;
        std::string taskD;
        int priority;
};

//  @brief Prints the tasks from the inputted vector.
//  @param taskList a vector that contains either tasks objects to complete or tasks objects that have yet to be completed.
void printTasks(std::vector<Task> taskList){
    cout << "\n--- Task List ---\n";
    for(int i = 0 ; i < taskList.size() ; i++){
                cout << i << ". " <<taskList[i].getTaskName() << endl;
        }
    cout << "-----------------\n";
}



int main(){
    cout << "Hello, Welcome to virtual habit tracker" << std::endl;
    String userInput;

    std::vector<Task> toDoTasks;
    std::vector<Task> completedTasks;

    //Access to menus.
    while(userInput != "q"){
        //First menu: options 1 or 2, and option 3 to add tasks to the list.
        cout << "Menus:" << endl;
        cout << "Option 1: Tasks to Do" << endl;
        cout << "Option 2: Tasks to Completed" << endl;
        cout << "Option 3: Add Tasks" << endl;
        cout <<"Enter user input: " <<std::flush;
        
        std::getline(cin,userInput);
        //Option 1 is to view tasks that have not been completed. 
        //Suboption menus to look at task description and then have an option to count as complete.
        if(userInput == "1"){
            printTasks(toDoTasks);
            cout << "Which tasks would you like to view?: " << endl;
            cin >> userInput;

            cout << "-----------------\n" << std::flush;
            cout << toDoTasks[std::stoi(userInput)].getTaskName() << ": " << endl;
            cout << toDoTasks[std::stoi(userInput)].getTaskDescription() << endl;
            cout << "-----------------\n" << std::flush;
            
            do
            {
                cout << "Would you like to view another task?(Y/N): ";
                cin >> userInput;
                if(userInput == "Y"){
                    printTasks(toDoTasks);
                    cout << "Which tasks would you like to view?: " << endl;
                    cin >> userInput;
                    cout << "-----------------\n" << std::flush;
                    cout << toDoTasks[std::stoi(userInput)].getTaskDescription() << endl;
                    cout << "-----------------\n" << std::flush;
                }
                else{
                    break;
                }

            } while (userInput != "N");
        }

        //Option 2 is to view tasks have been completed.
        //No suboption menus here.
        if(userInput == "2"){
            printTasks(completedTasks);
        }

        //Option 3 is to add tasks to the list.
        //No suboption menus here.
        if(userInput == "3"){
            do
            {
                //Task Name, // @bug the getline in this is not getting this line.
                cout << "Task Name: " << std::flush; 
                std::getline(cin, userInput); 
                String tempName = userInput; 

                //Task description passed in as a string
                cout << "Task Description: " << std::flush; 
                std::getline(cin, userInput); 
                String tempDescription = userInput;

                //Priority passed in as a temp integer.
                cout << "What is the priortiy rating of the task (1-100)?: " << std::flush;
                cin >> userInput;
                const int tempRating = std::stoi(userInput);

                //Creates new task object with the specifiers.
                Task newTask(tempName,tempDescription,tempRating);

                //Add to the toDoTasksVector which ends up as the last element.
                toDoTasks.push_back(std::move(newTask));

                //Asks user if they want to create another task.
                cout << "Would you like to create another tasks? (Y/N): ";
                cin >> userInput;
                
            }while (userInput != "N");
        }
        std::cin.ignore();
    }
    return 0; 
}