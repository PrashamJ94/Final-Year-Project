#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int rec(long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(33, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[rec(x)]++;
    }

    double answer = 0;
    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    cout << static_cast<long>(answer) << endl;

    return 0;
}

// //End of Code.
