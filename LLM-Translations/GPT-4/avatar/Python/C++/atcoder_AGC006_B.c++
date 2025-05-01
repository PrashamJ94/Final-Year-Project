Here is the C++ version of your Python code:

#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> x) {
    auto sub = [](vector<int>& y, bool debug) {
        while(y.size() > 1) {
            for(int i = 0; i < y.size() - 2; ++i) {
                sort(y.begin() + i, y.begin() + i + 3);
                y.erase(y.begin() + i);
            }
        }
        return y;
    };

    vector<int> y = sub(x, 0);
    if(y[0] == 2) {
        sub(x, 1);
        cout << "=" << x[0] << "\n";
    }
    return y[0];
}

int main() {
    int N, X;
    cin >> N >> X;

    if(X == 1 || X == 2*N - 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        vector<int> xs;
        if(X == 2*N - 2) {
            for(int i = N - 1; i <= X + 1; ++i) xs.push_back(i);
            for(int i = 1; i < N - 1; ++i) xs.push_back(i);
        } else {
            for(int i = 1; i < X - 1; ++i) xs.push_back(i);
            for(int i = X + 3; i < 2*N; ++i) xs.push_back(i);
            xs.insert(xs.begin() + N - 3, {X + 2, X - 1, X, X + 1});
        }
        for(int x : xs) {
            cout << x << "\n";
        }
    }
    return 0;
}

// End of Code
