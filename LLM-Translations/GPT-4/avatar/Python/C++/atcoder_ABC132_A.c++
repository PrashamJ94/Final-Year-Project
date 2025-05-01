#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;

    map<char, int> c;
    for(char& i : S) {
        c[i]++;
    }

    set<char> Sa;
    for(char& i : S) {
        Sa.insert(i);
    }

    if (Sa.size() != 2) {
        cout << "No";
        return 0;
    }

    for(char& i : Sa) {
        if (c[i] != 2) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
} // End of Code.
