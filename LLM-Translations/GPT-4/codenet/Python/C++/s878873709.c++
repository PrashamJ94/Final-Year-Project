#include <iostream>
#include <set>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> s = {1, 2, 4, 8, 16, 32, 64};
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        if (s.count(i)) {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}

// 
