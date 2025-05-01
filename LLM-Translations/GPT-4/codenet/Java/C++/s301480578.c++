#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int maxCount = 0;
    for (int l = 0; l < n - 1; l++) {
        int count = 0;
        while (l < n - 1 && h[l] >= h[l + 1]) {
            l++;
            count++;
        }
        maxCount = max(maxCount, count);
    }
    cout << maxCount << endl;
    return 0;
}

// 
