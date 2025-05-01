
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    vector<vector<int>> divs(100, vector<int>(primes.size()));
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            divs[i - 1][j] = 0;
            while (i % p == 0) {
                i /= p;
                divs[i - 1][j]++;
            }
        }
    }

    vector<int> divsum(primes.size(), 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < primes.size(); j++) {
            divsum[j] += divs[i - 1][j];
        }
    }

    auto num = [&](int n) {
        return count_if(divsum.begin(), divsum.end(), [&](int x) { return x >= n - 1; });
    };

    int ans = 0;

    ans += num(75);

    ans += num(15) * (num(5) - 1);

    ans += num(25) * (num(3) - 1);

    ans += num(5) * (num(5) - 1) * (num(3) - 2) / 2;

    cout << ans << endl;

    return 0;
}

// 
