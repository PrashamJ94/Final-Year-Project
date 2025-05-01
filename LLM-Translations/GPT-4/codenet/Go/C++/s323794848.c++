#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct op {
    bool rev, front;
    char c;
};

string rev(const string &s) {
    string r(s.rbegin(), s.rend());
    return r;
}

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<op> ops(Q);
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            cin >> f >> ops[i].c;
            if (f == 1) {
                ops[i].front = true;
            }
        }
    }
    vector<int> sum(Q + 1);
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    if (sum[0] % 2 == 1) {
        S = rev(S);
    }
    deque<char> deq;
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.push_back(ops[i].c);
                } else {
                    deq.push_front(ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.push_front(ops[i].c);
                } else {
                    deq.push_back(ops[i].c);
                }
            }
        }
    }
    string front(deq.begin(), deq.end());
    string back(deq.rbegin(), deq.rend());
    cout << front << S << back << endl;
    return 0;
}

// 
