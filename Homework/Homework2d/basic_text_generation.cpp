#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int countWords(const string& text) {
    stringstream ss(text);
    string word;
    int wordCount = 0;

    while (ss >> word) {
        ++wordCount;
    }

    return wordCount;
}

void generateText(unordered_map<string, vector<string> > map, string firstWord, int numWords) {

    string outPut = firstWord;
    string curr = firstWord;
    int wordCount = 1;

    // get the random number
    random_device rd;
    mt19937 gen(rd());

    while(wordCount < numWords){
        // && !map[curr].empty()
        if(map.find(curr) != map.end() && !map[curr].empty()) {
            // distribution range
            uniform_int_distribution<> dis(0, map[curr].size() - 1);
            int randomIndex = dis(gen);

            curr = map[curr][randomIndex];

            outPut += " " + curr;
            wordCount ++;
        } else {
            uniform_int_distribution<> dis(0, map[curr].size() - 1);
            int randomIndex = dis(gen);

            cout << curr << " broke it." << endl;
            break;
        }
    }
    cout << outPut << endl;
}

void trainModel(unordered_map<string, vector<string> >& myMap, ifstream& inputFile){
    string prev = "";
    string curr;
    string line;
    while(getline(inputFile, line)){
        stringstream ss(line);

        while (ss >> curr) {
            // do something with curr and prev
            myMap[prev].push_back(curr);

            prev = curr;
        }
    }

}

int main(int argc, char *argv[]) {
    unordered_map<string, vector<string> > myMap;

    string fileName = argv[1];
    ifstream inputFile(fileName);
    if(!inputFile){
        exit(1);
    }

    trainModel(myMap, inputFile);

    generateText(myMap, "", stoi(argv[2]));

    return 0;
}