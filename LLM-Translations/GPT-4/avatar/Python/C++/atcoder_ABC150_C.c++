#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = i+1;
    }
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int pn, qn, count = 0;
    do {
        if(v == p) {
            pn = count;
        }
        if(v == q) {
            qn = count;
        }
        count++;
    } while (next_permutation(v.begin(), v.end()));
    cout << abs(pn - qn) << endl;
    return 0;
} // End of Code
