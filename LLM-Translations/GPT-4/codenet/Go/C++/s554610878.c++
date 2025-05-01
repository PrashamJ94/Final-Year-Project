#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    vector<string> week = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    string s;
    cin >> s;
    int index = -1;
    for (int i = 0; i < week.size(); i++) {
        if (s == week[i]) {
            index = i;
            break;
        }
    }

    cout << 7 - index << endl;

    return 0;
}

// 
