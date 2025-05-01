#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int asub(int a, int b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

int abs(int a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K;
    for (int i = 1; i < N; i++) {
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            cnt = 1;
            end = t[i] + K;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

// 
