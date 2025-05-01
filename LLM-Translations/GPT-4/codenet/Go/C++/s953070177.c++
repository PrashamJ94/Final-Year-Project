#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int absint(int a) {
    return a < 0 ? -a : a;
}

int main() {
    istream& fp = cin;
    if (argc > 1) {
        fp = ifstream(argv[1]);
    }

    int n;
    fp >> n;

    vector<int> aa(n + 2, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        fp >> aa[i + 1];
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; ++i) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        cout << ans << endl;
    }

    return 0;
}

// 
