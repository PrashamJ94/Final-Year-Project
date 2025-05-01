#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n, val;
    unordered_map<int, int> hm;
    string input;

    getline(cin, input);
    stringstream ss(input);
    ss >> n;

    getline(cin, input);
    stringstream ss2(input);

    for(int i = 0; i < n; i++) {
        ss2 >> val;
        hm[val]++;
    }

    int ans = 0;
    for(auto& entry : hm) {
        int num = entry.second;
        if(num > entry.first)
            ans += num - entry.first;
        else if(num < entry.first)
            ans += num;
    }

    cout << ans << endl;

    return 0;
}
// 
