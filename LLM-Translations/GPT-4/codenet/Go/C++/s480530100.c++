#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : n(n), data(n, 0) {}

    void add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    int n;
    vector<int> data;

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    FenwickTree fw(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

// 
