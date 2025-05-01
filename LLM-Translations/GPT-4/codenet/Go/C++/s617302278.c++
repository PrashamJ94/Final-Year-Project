#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> NextIntsLine() {
    vector<int> ints;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        ints.push_back(num);
    }
    return ints;
}

int main() {
    int x;
    vector<int> tmp = NextIntsLine();
    x = tmp[0];
    int i = 1;
    int sum = 0;
    while (true) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}

// 
