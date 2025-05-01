#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> pre(n + 1);

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    long long min_diff = LLONG_MAX;

    for (int i = 1; i < n; i++)
    {
        long long val1 = pre[i], val2 = pre[n] - pre[i];

        min_diff = min(min_diff, abs(val1 - val2));
    }

    cout << min_diff << endl;

    return 0;
}
// 
