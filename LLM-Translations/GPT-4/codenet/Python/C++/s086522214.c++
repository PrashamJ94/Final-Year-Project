#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>
#include <sstream>

using namespace std;

// Function to split the string by a delimiter
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main() {
    string S;
    cin >> S;

    vector<string> T = split(S, '/');

    int date = stoi(T[1] + T[2]);
    if (date <= 430) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }

    return 0;
}

// 
