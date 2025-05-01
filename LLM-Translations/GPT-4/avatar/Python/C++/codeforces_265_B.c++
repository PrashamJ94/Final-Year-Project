#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        l.push_back(temp);
    }
    int ans = n - 1;
    int last = 0;
    for(auto i : l) {
        ans += abs(last - i) + 1;
        last = i;
    }
    cout << ans;
    return 0;
} // End of Code
