#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2)) {
        cout << "NO";
    } else {
        int k = accumulate(a.begin(), a.end(), 0) / (n * (n + 1) / 2);
        a.push_back(a[0]);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            sum1 += (k - a[i + 1] + a[i]) % n;
            sum2 += (k - a[i + 1] + a[i]) / n >= 0;
        }
        if (sum1 || sum2 != n) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }

    return 0;
}

// End of Code
