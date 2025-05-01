#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    bool flag = false;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.') {
            if (flag) {
                cout << 1;
                flag = false;
            } else {
                cout << 0;
            }
        } else {
            if (flag) {
                cout << 2;
                flag = false;
            } else {
                flag = true;
            }
        }
    }
    return 0;
}
// //End of Code.
