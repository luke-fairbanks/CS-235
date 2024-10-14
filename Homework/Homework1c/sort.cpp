#include <iostream>
#include <string>

using namespace std;

void sort(std::string& a, std::string& b, std::string& c) {
    // implement sort here
    string arr[] = {a,b,c};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++){
        // the bubble sort shrinks every time, iterating over one less item
        // because the last item is now the biggest
        for (int j = 0; j < n - i - 1; j++){
             // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    a = arr[0];
    b = arr[1];
    c = arr[2];
}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
