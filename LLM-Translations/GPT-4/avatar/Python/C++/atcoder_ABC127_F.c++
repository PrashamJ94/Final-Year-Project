#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    pair<long long, long long> ans = make_pair(0, 0);
    priority_queue<long long> p1;
    priority_queue<long long, vector<long long>, greater<long long>> p2;
    long long sum_b = 0, sum_p1 = 0, sum_p2 = 0;
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 2) {
            if(p1.size() == p2.size()) {
                cout << p2.top() << " " << sum_p1 - p1.size() * p2.top() + p2.size() * p2.top() - sum_p2 + sum_b << endl;
            } else {
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        } else {
            long long x, b;
            cin >> x >> b;
            sum_b += b;
            if(p1.empty() || p1.top() <= x) {
                p1.push(x);
                sum_p1 += x;
            } else {
                p2.push(x);
                sum_p2 += x;
            }
            if(p1.size() < p2.size()) {
                long long k = p2.top();
                p2.pop();
                p1.push(k);
                sum_p2 -= k;
                sum_p1 += k;
            }
            if(p1.size() - 1 > p2.size()) {
                long long k = p1.top();
                p1.pop();
                p2.push(k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }
    return 0;
} // End of Code
