#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    long long const_value = 0;
    long long left_sum = 0;
    long long right_sum = 0;
    int cnt = 0;

    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            long long a, b;
            cin >> a >> b;
            const_value += b;

            if (cnt % 2 == 0) {
                if (right.empty()) {
                    left.push(a);
                    left_sum += a;
                    cnt++;
                    continue;
                }

                long long c = right.top();
                right.pop();
                right_sum -= c;

                if (a <= c) {
                    left.push(a);
                    right.push(c);
                    left_sum += a;
                    right_sum += c;
                } else {
                    left.push(c);
                    right.push(a);
                    left_sum += c;
                    right_sum += a;
                }
            } else {
                long long c = left.top();
                left.pop();
                left_sum -= c;

                if (a <= -c) {
                    left.push(-a);
                    right.push(-c);
                    left_sum -= a;
                    right_sum += c;
                } else {
                    left.push(-c);
                    right.push(a);
                    left_sum += c;
                    right_sum += a;
                }
            }
            cnt++;
        } else {
            long long tmp = left.top();
            cout << tmp << " " << const_value - left_sum + right_sum + tmp * (cnt % 2) << endl;
        }
    }

    return 0;
}
// 
