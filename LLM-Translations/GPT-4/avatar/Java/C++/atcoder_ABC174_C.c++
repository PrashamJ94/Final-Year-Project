#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <numeric>
#include <functional>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <iomanip>

using namespace std;

int readInt() {
    int x;
    cin >> x;
    return x;
}

int solve() {
    int K = readInt();
    if (K % 2 == 0 || K % 5 == 0) return -1;
    if (K % 7 == 0) K /= 7;
    K *= 9;
    int ans = 1;
    int remainder = 10 % K;
    while (remainder != 1) {
        ans++;
        remainder = remainder * 10 % K;
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// //End of Code.
