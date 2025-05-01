#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <functional>
#include <cstring>

using namespace std;

const int magic = 1000000007;

int N;
int p[200000];

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int X;
    cin >> X >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            cout << X - i << endl;
            exit(0);
        }
        if (find(X + i) == 1) {
            cout << X + i << endl;
            exit(0);
        }
    }
}

int main() {
    solve();
    return 0;
}

// 
