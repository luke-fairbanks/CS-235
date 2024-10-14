#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;

    // use getline with the delimiter to split the string
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
};

int main(int argc, char *argv[]) {
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "NOPE" << endl;
        return 1;
    }

    ofstream outputFile(argv[2]);

    string line;

    while(getline(inputFile, line)) {
        vector<string> words = split(line, ' ');
        outputFile << words[1] <<", "<<words[0]<<": "<<std::stoi(words[2])*std::stod(words[3]) << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}