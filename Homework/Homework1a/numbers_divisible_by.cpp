// :D
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int start = std::atof(argv[1]);
    int end = std::atof(argv[2]);
    int divisor = std::atof(argv[3]);

    if (start<end){
        for (int i = start; i<=end; i++ ) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        };
    }
    else if (start>end){
        for (int i = start; i >= end; i--) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }

}