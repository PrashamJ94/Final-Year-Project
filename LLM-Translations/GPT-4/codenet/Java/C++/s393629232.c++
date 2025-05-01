#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maxv = numeric_limits<int>::min();
    int minv;
    cin >> minv;
    for (int i = 1; i < n; i++) {
        int ri;
        cin >> ri;
        maxv = max(maxv, ri - minv);
        minv = min(minv, ri);
    }
    cout << maxv << endl;
    return 0;
}

// 
