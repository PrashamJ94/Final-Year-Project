#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arrA(n);
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
    }

    vector<int> cumSumA(n + 1);
    cumSumA[0] = 0;
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    double inf = numeric_limits<double>::infinity();
    double ans = inf;
    for (int i = 1; i < n; i++) {
        if (abs(cumSumA[n] - (cumSumA[i] * 2)) < ans) {
            ans = abs(cumSumA[n] - cumSumA[i] * 2);
        }
    }

    cout << static_cast<int>(ans) << endl;
}

// 
