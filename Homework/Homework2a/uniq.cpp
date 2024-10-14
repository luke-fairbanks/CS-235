#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

bool lineNotInList(set<string> lst, string line){
    auto search = lst.find(line);
    if(search == lst.end()){
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here
    if (argc == 2){
        string fileName = argv[1];
        ifstream inputFile(fileName);
        if(!inputFile){
            exit(1);
        }
        set<string> items;
        string line;
        while(getline(inputFile, line)){
            if(lineNotInList(items, line)){
                cout << line << endl;
                items.insert(line);
            }
        }

    } else {
        set<string> items;
        string input;
        bool go = true;
        while(go){
            getline(cin, input);
            if (input=="") {
                go = false;
            }
            if(lineNotInList(items, input)){
                items.insert(input);
                cout << input << endl;
            }
        }
    }
    return 0;
}
