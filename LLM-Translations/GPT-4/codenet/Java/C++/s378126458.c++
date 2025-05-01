#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 122C
 * 
 * This problem requires prefix sum array
 * Let's define a boolean array k[i] 
 * k[i] = true when s[i] == 'A' and s[i+1] == 'C'
 * Make a prefix sum array of k and then query with it
 * 
 * COMMON MISTAKE MAKE SURE YOU DO R-1 BECAUSE S[R+1] GOES OVER THE RANGE
 * COMMON MISTAKE THIS IS ONE-INDEXED STRING
 * 
 * Time Complexity O(N), Memory Complexity O(N)
 * 
 */

int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<int> pre(N + 1, 0);

    for (int i = 1; i < N; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            pre[i] = 1; // initially the prefix sum array is the k array
        }
    }

    // Building the psa
    for (int i = 1; i < N; i++) {
        pre[i] += pre[i - 1];
    }

    // Querying
    while (Q-- > 0) {
        int l, r;
        cin >> l >> r;
        r--;
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}

// 
