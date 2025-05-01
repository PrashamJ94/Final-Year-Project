#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        d += arr[i] % 2;
    }
    cout << (d % 2 == 0 ? "YES" : "NO") << endl;
    return 0;
}
// 
