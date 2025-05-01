#include <iostream>
#include <cmath>

using namespace std;

void solve(int A, int B, int n) {
    if (A == 0) {
        if (B == 0) cout << 1 << endl;
        else cout << "No solution" << endl;
        return;
    }
    if (B % A != 0) {
        cout << "No solution" << endl;
        return;
    }
    B /= A;
    bool neg = B < 0;
    if (neg && n % 2 == 0) {
        cout << "No solution" << endl;
        return;
    }
    if (neg) B = -B;
    for (int x = 0; x <= B; x++) {
        if (pow(x, n) == B) {
            cout << (neg ? -x : x) << endl;
            return;
        }
    }
    cout << "No solution" << endl;
}

int main() {
    int A, B, n;
    cin >> A >> B >> n;
    solve(A, B, n);
    return 0;
}

// //End of Code.
