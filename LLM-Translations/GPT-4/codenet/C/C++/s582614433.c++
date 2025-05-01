#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef struct edge { ll p, i; string s; } E;

bool esort(const E &a, const E &b) {
    if (a.s != b.s) return a.s < b.s;
    return a.p > b.p;
}

int main() {
    ll n;
    cin >> n;
    vector<E> data(n);
    for (ll i = 0; i < n; i++) {
        cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }
    sort(data.begin(), data.end(), esort);
    for (ll i = 0; i < n; i++) cout << data[i].i + 1 << endl;
}

// 
