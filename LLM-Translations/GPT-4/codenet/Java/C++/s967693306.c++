#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>

using namespace std;

class Main {
public:
    static const long long INF = LLONG_MAX / 2;
    static const int MOD = 1'000'000'007;
    static const int SIZE = 1'000'000;
    vector<long long> fac = vector<long long>(SIZE);
    vector<long long> inv = vector<long long>(SIZE);
    vector<long long> finv = vector<long long>(SIZE);

    void solve() {
        int n, m;
        cin >> n >> m;
        map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s, c;
            cin >> s >> c;
            if (map.find(s) != map.end() && map[s] != c) {
                cout << -1 << endl;
                exit(0);
            }
            map[s] = c;
        }

        for (int i = 0; i < 1000; i++) {
            string s = to_string(i);
            bool flag = true;
            if (s.length() < n) continue;
            for (int j = 0; j < n; j++) {
                if ((map.find(j + 1) != map.end() && map[j + 1] != s.at(j) - '0') || (map.find(j + 1) == map.end() && s.at(j) - '0' != 0)) {
                    if (map.find(j + 1) == map.end() && j == 0 && s.at(j) - '0' == 1) {
                        continue;
                    }
                    flag = false;
                    break;
                }
            }
            if (flag && s.length() == n) {
                cout << s << endl;
                exit(0);
            }
        }

        cout << -1 << endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}

// 
