#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> p(x), q(y), r(c), pq;

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        if (i < x) p[i] = temp;
    }
    sort(p.rbegin(), p.rend());

    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        if (i < y) q[i] = temp;
    }
    sort(q.rbegin(), q.rend());

    for (int i = 0; i < c; i++) {
        int temp;
        cin >> temp;
        r[i] = temp;
    }
    sort(r.rbegin(), r.rend());

    pq = vector<int>(p);
    pq.insert(pq.end(), q.begin(), q.end());
    sort(pq.begin(), pq.end());

    for (int i = 0; i < min(x + y, min(a + b, c)); i++) {
        if (pq[i] < r[i]) {
            pq[i] = r[i];
        }
    }

    long long sum = 0;
    for (int i = 0; i < pq.size(); i++) {
        sum += pq[i];
    }

    cout << sum << endl;

    return 0;
}
// 
