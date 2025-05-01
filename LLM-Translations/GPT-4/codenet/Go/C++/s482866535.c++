#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char *argv[]) {
    istream *input = &cin;
    ifstream file;
    if (argc > 1) {
        file.open(argv[1]);
        input = &file;
    }

    int n;
    *input >> n;
    vector<int> mm(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        *input >> mm[i] >> mm[i + 1];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
// 
