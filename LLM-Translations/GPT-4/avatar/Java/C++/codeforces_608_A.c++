#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int main() {
    int n, s, f, t;
    int max = 0;
    cin >> n >> s;
    while (n-- > 0) {
        cin >> f >> t;
        if (max < f + t) {
            max = f + t;
        }
    }
    cout << max(max, s) << endl;
    return 0;
}

// //End of Code.
