
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int a, b;
    unordered_set<int> counter;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (h[a-1] < h[b-1]) {
            counter.insert(a);
        } else if (h[a-1] > h[b-1]) {
            counter.insert(b);
        } else if (h[a-1] == h[b-1]) {
            counter.insert(a);
            counter.insert(b);
        }
    }
    cout << n - counter.size() << endl;
    return 0;
}

// 
