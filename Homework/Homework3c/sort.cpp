#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void insertionSort(vector<string>& list){
    for(int i = 1; i<list.size(); i++){
        int j = i;
        auto item = list[j];
        while(j> 0 && list[j-1]>item){
            list[j] = list[j-1];
            j--;
        }
        list[j]=item;
    }

    for (int i = 0; i<list.size(); i++){
        cout << list[i] << endl;
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here
    vector<string> lst;

    if (argc > 1) {
        ifstream in(argv[1]);
        string line;
        while (getline(in, line)){
            lst.push_back(line);
        }
    } else {
        string line;
        getline(cin, line);
        while(line != ""){
            lst.push_back(line);
            getline(cin, line);
        }
    }

    insertionSort(lst);
    return 0;
}
