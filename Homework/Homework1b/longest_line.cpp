//  :-)
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string findLongestString(string fileStr) {
    string longestLine;
    int longestCount = 0;

    ifstream inputFile(fileStr);

    string line;
    while(getline(inputFile, line)){
        int cantidad = 0;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            cantidad++;
        }
        if (cantidad > longestCount){
            longestCount = cantidad;
            longestLine = line;
        }
    }

    return longestLine;
}

int main(int argc, char *argv[]) {
    string line = "I am an eye witness";

    string longestString = findLongestString(argv[1]);
    cout << longestString << endl;
}