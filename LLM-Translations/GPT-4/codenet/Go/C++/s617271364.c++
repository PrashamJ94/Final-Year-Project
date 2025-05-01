#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>

using namespace std;

int N, ss, ans, A, B, C;

void dfs(vector<int>& dp, int times, const vector<int>& arr);
int calc(const vector<int>& dp, const vector<int>& arr);
int min(int a, int b);
int abs(int a);
int sum(const vector<int>& a);

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> N >> A >> B >> C;

    vector<int> arr(N);
    vector<int> dp(N);
    ans = 10000;
    ss.clear();

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss2(line);
        ss2 >> arr[i];
    }

    dfs(dp, 0, arr);

    cout << ans << endl;

    return 0;
}

void dfs(vector<int>& dp, int times, const vector<int>& arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

int calc(const vector<int>& dp, const vector<int>& arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;

    vector<int> memo(4);
    for (size_t i = 0; i < dp.size(); i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
        }
    }
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    return cost;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

int sum(const vector<int>& a) {
    int sum = 0;
    for (const int& num : a) {
        sum += num;
    }
    return sum;
}

// 
