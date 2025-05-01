#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    int a, b;
    ss >> a >> b;
    int c = a - b * 2;
    if (c < 0) c = 0;
    cout << c << endl;
    return 0;
}

// //End of Code
