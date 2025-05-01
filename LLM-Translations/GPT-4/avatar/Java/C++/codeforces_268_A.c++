#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, result = 0;
    cin >> n;

    vector<int> h(n), g(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> g[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i] == g[j]) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}

// //End of Code
