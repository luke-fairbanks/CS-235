// :)
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
    int val = std::stoi(argv[1]);
    cout << val << endl;
    while (val != 1){
        if (val % 2 == 0){
            val = val/2;
        }
        else {
            val = val*3;
            val += 1;
        }
        cout << val << endl;
    }
    return 0;
}