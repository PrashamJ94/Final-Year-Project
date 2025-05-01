#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, l = 0, c = 1;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == l)
            c += 1;
        else
            c = 1;
        l = a[i];
    }

    if (c + k > n)
        cout << (n - c) << endl;
    else
        cout << -1 << endl;

    return 0;
}

// //End of Code.
