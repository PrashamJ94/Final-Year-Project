#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<int> ans;
    for (int i = x + n - 1; i < x + n + max - 1; ++i) {
        ans.push_back(i % max + 1);
    }
    for (const auto& e : ans) {
        cout << e << endl;
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}
// //End of Code
