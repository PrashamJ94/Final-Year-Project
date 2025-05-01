#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;

const int Black = 35;

int countBlack(int h, int w, vector<vector<int>> &m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int a, vector<vector<int>> &m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            vector<vector<int>> tmp(h, vector<int>(w));
            for (int j = 0; j < h; j++) {
                tmp[j] = m[j];
            }
            for (int j = 0; j < h; j++) {
                int hPainted = (1 << j & i);
                if (hPainted > 0) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                int wPainted = (1 << j & k);
                if (wPainted > 0) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> m(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            m[i][j] = s[j];
        }
    }

    int answer = solve(h, w, k, m);
    cout << answer << endl;

    return 0;
}

// 
