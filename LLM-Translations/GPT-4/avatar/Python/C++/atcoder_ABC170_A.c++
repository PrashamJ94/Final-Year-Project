#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int temp;
    while (cin >> temp) {
        a.push_back(temp);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
} //End of Code
