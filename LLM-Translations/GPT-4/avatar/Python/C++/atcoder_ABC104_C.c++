#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int D, G;
    cin >> D >> G;
    vector<pair<int, int>> PC(D);
    for (int i = 0; i < D; i++) {
        cin >> PC[i].first >> PC[i].second;
    }
    int ans = 1e9;
    for (int i = 0; i < (1 << D); i++) {
        int score = 0, problem = 0;
        for (int j = 0; j < D; j++) {
            if (i >> j & 1) {
                score += 100 * (j + 1) * PC[j].first + PC[j].second;
                problem += PC[j].first;
            }
        }
        if (score < G) {
            for (int j = D - 1; j >= 0; j--) {
                if (i >> j & 1) continue;
                if (score + 100 * (j + 1) * (PC[j].first - 1) >= G) {
                    problem += (G - score + 100 * (j + 1) - 1) / (100 * (j + 1));
                    score = G;
                } else {
                    score += 100 * (j + 1) * PC[j].first;
                    problem += PC[j].first;
                }
            }
        }
        ans = min(ans, problem);
    }
    cout << ans << endl;
    return 0;
} // End of Code
