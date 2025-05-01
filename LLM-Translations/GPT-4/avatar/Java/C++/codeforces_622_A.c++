#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

void solve() {
    long position;
    cin >> position;
    long nrstSeqStartIndx = 1;
    
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    
    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    cout << (position - startIndex) + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}

// //End of Code.
