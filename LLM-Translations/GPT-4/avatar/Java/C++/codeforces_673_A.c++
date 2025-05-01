#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        a.push_back(value);
    }
    int result, pos = 0, flag = 0;
    if (a.at(0) > 15) {
        result = 15;
    } else {
        for (int i = 1; i < n; i++) {
            if (a.at(i) - a.at(i - 1) > 15) {
                pos = i - 1;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            result = a.at(pos) + 15;
        } else {
            result = a.at(n - 1) + 15;
        }
    }
    if (result > 90) {
        result = 90;
    }
    cout << result << endl;
    return 0;
}

// //End of Code.
