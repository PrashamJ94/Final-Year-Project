#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <iterator>

using namespace std;

class Main {
public:
    void solve() {
        int a, b;
        cin >> a >> b;
        cout << max(0, a - 2 * b) << endl;
    }

    int main() {
        solve();
        return 0;
    }
};

int main() {
    Main myMain;
    myMain.main();
    return 0;
}
// 
