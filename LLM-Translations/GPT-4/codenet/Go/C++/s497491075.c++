#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> splitToInts(string s, char delimiter) {
    vector<int> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(stoi(token));
    }
    return result;
}

int main() {
    int N, D;
    cin >> N >> D;
    cin.ignore();

    int count = 0;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        vector<int> points = splitToInts(line, ' ');

        double d = sqrt(static_cast<double>(points[0] * points[0] + points[1] * points[1]));
        if (static_cast<double>(D) >= d) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}

// 
