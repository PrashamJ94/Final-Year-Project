
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, v, b, w, t;
    cin >> a >> v;
    cin >> b >> w;
    cin >> t;

    if (a == b) {
        cout << "YES" << endl;
    } else if (v <= w) {
        cout << "NO" << endl;
    } else {
        if (t < abs(a - b) / (double)(v - w)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}

// 
