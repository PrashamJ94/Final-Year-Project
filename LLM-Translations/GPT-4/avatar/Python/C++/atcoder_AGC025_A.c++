#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;
    vector<string> a = { "10", "100", "1000", "10000", "100000" };
    int new_value = 0;
    for (char c : n) {
        new_value += c - '0';
    }
    if (find(a.begin(), a.end(), n) != a.end()) {
        cout << 10 << endl;
    }
    else {
        cout << new_value << endl;
    }
    return 0;
}
// End of Code
