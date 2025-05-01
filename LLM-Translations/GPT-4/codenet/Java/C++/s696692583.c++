#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void tr(initializer_list<char> os) {
    for (const char &c : os) {
        cerr << c;
    }
    cerr << endl;
}

int main() {
    int my1, my2, enemy1;
    while (cin >> my1 >> my2 >> enemy1) {
        bool used[11];
        memset(used, false, sizeof(used));
        used[my1] = true;
        used[my2] = true;
        used[enemy1] = true;
        int all = 0;
        int safe = 0;
        for (int i = 1; i <= 10; i++) if (!used[i]) {
            all++;
            if (my1 + my2 + i <= 20) safe++;
        }
        if (safe * 2 >= all) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

char solve(vector<vector<int>> &a) {
    char s[] = {'d', 'o', 'x'};
    for (int side = 1; side <= 2; side++) {
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == side && a[i][1] == side && a[i][2] == side) return s[side];
            if (a[0][i] == side && a[1][i] == side && a[2][i] == side) return s[side];
        }
        if (a[0][0] == side && a[1][1] == side && a[2][2] == side) return s[side];
        if (a[0][2] == side && a[1][1] == side && a[2][0] == side) return s[side];
    }
    return 'd';
}

// 
