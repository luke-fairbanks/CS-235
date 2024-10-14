#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here

    priority_queue<string> queue;
    string input = " ";
    while (input != ""){
        cout << "What do you want to do? ";
        getline(cin, input);
        if(input == "add"){
            string name;
            string priority;

            cout << "Name: ";
            getline(cin, name);

            cout << "Priority: ";
            getline(cin, priority);

            if(stoi(priority)<10){
                priority = "0"+priority;
            }

            queue.push(priority+" - "+name);
        } else if (input == "take"){
            if (queue.empty()){
                cout << "There are no more people in line" << endl;
            } else {
                cout << queue.top() << endl;
                queue.pop();
            }
        } else if (input != "") {
            cout << input << " isn't a valid operation" << endl;
        }
    }

    return 0;
}
