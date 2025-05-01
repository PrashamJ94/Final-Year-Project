#include <iostream>
using namespace std;

int maxLeft(int n) {
    return n > 2 ? n - 2 : 0;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << maxLeft(n) << endl;
    }
    return 0;
}

// //End of Code.
