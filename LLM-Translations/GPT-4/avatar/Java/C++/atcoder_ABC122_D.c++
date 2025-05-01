#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class atcoder_ABC122_D {
    int N;
    long long MOD = 1000000007LL;
    vector<string> TOKENS = {"A", "C", "G", "T"};
    vector<map<string, long long>> memo;

public:
    atcoder_ABC122_D() {
        cin >> N;
        memo.resize(N + 1);
    }

    long long calc() {
        return dfs(0, "TTT");
    }

    bool isOK(string last4) {
        if (last4.find("AGC") != string::npos) {
            return false;
        }
        for (int i = 0; i < 3; ++i) {
            swap(last4[i], last4[i + 1]);
            if (last4.find("AGC") != string::npos) {
                return false;
            }
            swap(last4[i], last4[i + 1]);
        }
        return true;
    }

    long long dfs(int current, string last3) {
        if (memo[current].find(last3) != memo[current].end()) {
            return memo[current][last3];
        }
        if (current == N) {
            return 1;
        }
        long long result = 0;
        for (const string &c : TOKENS) {
            if (isOK(last3 + c)) {
                result = (result + dfs(current + 1, last3.substr(1) + c)) % MOD;
            }
        }
        memo[current][last3] = result;
        return result;
    }
};

int main() {
    atcoder_ABC122_D ins;
    cout << ins.calc() << endl;
    return 0;
}

// //End of Code.
