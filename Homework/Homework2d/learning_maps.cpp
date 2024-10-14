#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Declare an unordered_map with string keys and vector<string> values
    unordered_map<string, vector<string> > myMap;

    // Example usage: Adding elements to the unordered_map
    myMap["key1"].push_back("value1");
    myMap["key1"].push_back("value2");
    myMap["key2"].push_back("value3");

    // Example usage: Iterating over the unordered_map
    for (const auto& pair : myMap) {
        cout << "Key: " << pair.first << " -> Values: ";
        for (const auto& val : pair.second) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}