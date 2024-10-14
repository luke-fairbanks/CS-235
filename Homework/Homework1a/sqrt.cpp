#include <iostream>

#include <cstdlib>  // atof
using std::abs;

using namespace std;

const double EPSILON = 0.0001;

// :)

int main(int argc, char *argv[]){
    double val = std::stod(argv[1]);
    double sqrt;
    if (val<0){
        cout << "Input must be greater than 0" << endl;
        return 1;
    }
    double upper = val;
    double lower = 0;
    // while the absolute value of the difference between our value
    // and the square root of our number is greater than the
    // allowed difference:
    while(abs(val-(sqrt*sqrt)) > EPSILON){
        // calculate the number in the middle of our upper and lower bounds
        double middle = abs(upper - ((upper-lower)/2));
        sqrt = middle;
        cout << sqrt <<" ("<< sqrt*sqrt<<")"<< endl;

        // if the number was too small, our lower bound now becomes our lower bound
        if(sqrt*sqrt < val){
            lower = sqrt;
        }
        // if the number was too big, our lower bound now becomes our upper bound
        else if (sqrt*sqrt > val){
            upper = sqrt;
        }

    }
    return 0;
}
