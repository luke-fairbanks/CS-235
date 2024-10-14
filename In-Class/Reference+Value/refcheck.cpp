#include <iostream>

using namespace std;

void funcFooFanda (int& b) {
    b = 2;
}


int main() {
    int a = 3;

    funcFooFanda(a);

    cout << "a = " << a << endl;

    return 0;
}