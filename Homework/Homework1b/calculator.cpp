//  :)
// DONE
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    string operation;
    string leftOp;
    string rightOp;
    while (true){
    cout << "operation: ";
    getline(cin, operation);

    while (operation != "add" && operation != "subtract" && operation != "multiply" && operation != "divide" && operation != "mod"){
        if (operation == ""){
            return 0;
        }
        cout << operation << " isn't a valid operation" << endl;
        cout << "operation: ";
        getline(cin, operation);
    }

    cout << "left operand: ";
    getline(cin, leftOp);

    cout << "right operand: ";
    getline(cin, rightOp);

    if (operation == "add") {
        cout << std::stod(leftOp) + std::stod(rightOp) << endl;
    } else if (operation == "subtract") {
        cout << std::stod(leftOp) - std::stod(rightOp) << endl;
    } else if (operation == "multiply") {
        cout << std::stod(leftOp) * std::stod(rightOp) << endl;
    } else if (operation == "divide") {
        cout << std::stod(leftOp) / std::stod(rightOp) << endl;
    } else if (operation == "mod") {
        cout << std::stoi(leftOp) % std::stoi(rightOp) << endl;
    };
    }
}
