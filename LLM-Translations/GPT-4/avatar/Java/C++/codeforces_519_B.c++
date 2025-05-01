#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a = 0, b = 0, c = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        a += arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        b += arr[i];
    }

    for (int i = 0; i < n - 2; i++) {
        cin >> arr[i];
        c += arr[i];
    }

    int x = a - b, y = b - c;
    cout << x << endl;
    cout << y << endl;
    return 0;
}

// //End of Code.
