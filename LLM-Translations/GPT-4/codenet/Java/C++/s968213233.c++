#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

class Main {
public:
    Main(istream &in, ostream &out, int test) {
        int N;
        in >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            in >> A[i];
        sort(A.begin(), A.end());

        long long res = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> q([](pair<int, int> a, pair<int, int> b) {
            return min(a.first, a.second) < min(b.first, b.second);
        });
        q.push(make_pair(A[N - 1], A[N - 1]));

        for (int i = N - 2; i >= 0; i--) {
            int a = A[i];
            pair<int, int> place = q.top();
            q.pop();
            res += min(place.first, place.second);
            q.push(make_pair(place.first, a));
            q.push(make_pair(a, place.second));
        }
        out << res << endl;
    }
};

int main() {
    // int T;
    // cin >> T;
    for (int t = 1; t <= 1; t++) {
        Main solution(cin, cout, t);
    }

    return 0;
}

// 
