#include <bits/stdc++.h>
using namespace std;

bool check_normal_dict (string u , int pointer1 , int pointer2, int N ) {
    for (int i = 0; i < N ; i++ ) {
        if (u [ pointer1 + i ] > u [ pointer2 + i ]) {
            return true;
        } 
        else if (u [ pointer1 + i ] < u [ pointer2 + i ]) {
            return false;
        }
    }
    return false;
}

string get_last_dict (string s_str, int N) {
    string U = s_str + string(s_str.rbegin(), s_str.rend());
    char c = *min_element(s_str.begin(), s_str.end());
    int p = U.find(c);
    int minindex = p;
    p += 1;
    while (p <= N ) {
        if (U [ p ] == c ) {
            if (check_normal_dict ( U , minindex , p, N )) {
                minindex = p;
            }
        }
        p += 1;
    }
    return U.substr(minindex, N);
}

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool aaaa = false;
    if (K >= 15 || (1 << K) >= N) {
        aaaa = true;
    }
    if (aaaa) {
        cout << string(N, *min_element(S.begin(), S.end()));
        return 0;
    }
    S = get_last_dict (S, N);
    if (K == 1) {
        cout << S;
        return 0;
    }
    int count = 0;
    for (char c : S) {
        if (c == S [ 0 ]) {
            count += 1;
        } else {
            break;
        }
    }
    if (count * (1 << (K - 1)) >= N ) {
        cout << string(N, S[0]);
    } else {
        S = string(count * ((1 << (K - 1)) - 1), S[0]) + S;
        cout << S.substr(0, N);
    }
    return 0;
}
// End of Code.
