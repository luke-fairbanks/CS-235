#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cstdlib>

using namespace std;

void linesFromCin(int numLines){
    for(int i = 0; i<abs(numLines); i++){
        string a;
        getline(cin, a);
        cout << a << endl;
    }
}

void linesFromFile(string fileName, int numLines) {
    ifstream inputFile(fileName);
    if (!inputFile){
        cout << "ERROR: can't open " << fileName;
        exit(1);
    };
    string line;
    int lineCount = 0;
    while(getline(inputFile, line) && lineCount < abs(numLines)){
        cout << line << endl;
        lineCount++;
    }
}

bool isInteger(const string& str) {
    // Handle negative numbers by allowing the first character to be '-'
    int start = 0;
    if (str[0] == '-') {
        start = 1; // Skip the minus sign for checking digits
    }

    // Check each character after the optional minus sign
    for (int i = start; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false; // If a non-digit character is found
        }
    }

    // Empty string or only a minus sign is not valid
    return str.length() > start;
}

int main(int argc, char const* argv[]) {
    // Write your code here
    if (argc == 1){
        // no arguments provided
        linesFromCin(10);
    } else if(argc == 2) {
        // only filename
        if (!isInteger(argv[1])){
            linesFromFile(argv[1], 10);
        }
        // only linecount
        else {
            linesFromCin(std::stoi(argv[1]));
        }
    // both arguments
    } else {
        linesFromFile(argv[2], std::stoi(argv[1]));
    }

    return 0;
}
