#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i] - 1] = i;
    }
    int res = 0;
    for(int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);
    }
    cout << res;
    return 0;
} // End of Code.
