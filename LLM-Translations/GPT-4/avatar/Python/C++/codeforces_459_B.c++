#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, ac, bc;
    cin >> n;
    vector<long long> l1(n);
    for (int i = 0; i < n; i++) {
        cin >> l1[i];
    }
    sort(l1.begin(), l1.end());
    a = l1[n-1];
    b = l1[0];
    if (a == b) {
        cout << a - b << " " << n * (n - 1) / 2;
    }
    else {
        ac = count(l1.begin(), l1.end(), a);
        bc = count(l1.begin(), l1.end(), b);
        cout << a - b << " " << ac * bc;
    }
    return 0;
} //End of Code
