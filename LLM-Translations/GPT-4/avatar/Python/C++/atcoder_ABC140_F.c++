#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

string mainFunc() {
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), compare);
    vector<bool> flag(N, true);
    vector<int> cur;
    cur.push_back(S[0]);
    flag[0] = false;
    for(int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur.size();
        for(int k = 0; k < S.size(); k++) {
            if(flag[k] && S[k] < cur[j]) {
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                if(j == jM) {
                    break;
                }
            }
        }
        if(j != jM) {
            return "No";
        }
        sort(cur.begin(), cur.end(), compare);
    }
    return "Yes";
}

int main() {
    cout << mainFunc() << endl;
    return 0;
}

// End of Code
