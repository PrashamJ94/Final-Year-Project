#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string Si;
    cin >> Si;
    reverse(Si.begin(), Si.end());
    char S[Si.length()+1];
    strcpy(S, Si.c_str());

    long long dp[13] = {1};

    for (int i = 0, d = 1; i < strlen(S); i++, d = d * 10 % 13) {
        long long nd[13] = {0};

        char c = S[i];

        if (isdigit(c)) {
            int x = (c - '0') * d;

            for (int j = 0; j < 13; j++) {
                nd[(j + x) % 13] = dp[j];
            }
        } else {
            for (int xi = 0; xi < 10; xi++) {
                int x = xi * d;

                for (int j = 0; j < 13; j++) {
                    int ni = (j + x) % 13;
                    nd[ni] = (nd[ni] + dp[j]) % 1000000007;
                }
            }
        }

        for (int i = 0; i < 13; i++) {
            dp[i] = nd[i];
        }
    }

    cout << dp[5] << endl;
    return 0;
}

// 
