#include <iostream>
#include <string>

using namespace std;

const int BIG_NUM = 2000000000;
const int MOD = 1000000007;

int main() {
    string inputed;
    int ans;

    while (true) {
        getline(cin, inputed);
        if (inputed.length() == 1 && inputed == "0") break;

        ans = 0;
        for (int i = 0; i < inputed.length(); i++) {
            ans += inputed[i] - '0';
        }

        cout << ans << endl;
    }

    return 0;
}

// 
