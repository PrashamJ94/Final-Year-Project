#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
const int inf = INT_MAX;

class Pair {
public:
    int a, b;
    Pair(int a, int b) : a(a), b(b) {}
};

bool comparePairs(const Pair &p1, const Pair &p2) {
    return p1.b < p2.b;
}

bool in(int c, int a, int z) {
    return c >= a && c < z;
}

bool out(int c, int a, int z) {
    return !in(c, a, z);
}

int btoi(bool b) {
    return b ? 1 : 0;
}

bool itob(int a) {
    return a != 0;
}

int max(const vector<int> &a) {
    int r = a[0];
    for (size_t i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

int min(const vector<int> &a) {
    int r = a[0];
    for (size_t i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

int sum(const vector<int> &a) {
    int r = 0;
    for (size_t i = 0; i < a.size(); i++) {
        r += a[i];
    }
    return r;
}

int pro(const vector<int> &a) {
    int r = a[0];
    for (size_t i = 1; i < a.size(); i++) {
        r *= a[i];
    }
    return r;
}

vector<int> fill(const vector<int> &a, int n) {
    vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        result[i] = n;
    }
    return result;
}

int minmax(int a, int b) {
    return a > b ? b : a;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int ceil(int a, int b) {
    return a % b != 0 ? 1 : 0;
}

void printStrings(const vector<string> &out) {
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void printInts(const vector<int> &out) {
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    string N;
    cin >> N;
    int n = 0;
    for (size_t i = 0; i < N.size(); i++) {
        n += N[i] - '0';
    }

    int m;
    istringstream(N) >> m;
    if (m % n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// 
