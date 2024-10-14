#include <iostream>

using namespace std;

// argc is the count of arguments
// argv is the value of arguments
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "prod requires 2 arguments" << endl;
        return 1;
    }

    double num1 = std::atof(argv[1]);
    double num2 = std::atof(argv[2]);

    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

    return 0;
}