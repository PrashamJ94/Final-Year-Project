#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    auto num_inp = []() -> int {
        int n;
        cin >> n;
        return n;
    };

    auto arr_inp = []() -> vector<int> {
        vector<int> arr;
        int temp;
        while(cin >> temp) {
            arr.push_back(temp);
        }
        return arr;
    };

    auto sp_inp = []() -> pair<int, int> {
        int a, b;
        cin >> a >> b;
        return make_pair(a, b);
    };

    auto str_inp = []() -> string {
        string str;
        cin >> str;
        return str;
    };
}

// End of Code

