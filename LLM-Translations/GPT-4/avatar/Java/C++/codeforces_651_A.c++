#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = 0;
    if (a == 1 && b == 1) {
        cout << 0 << endl;
    } else {
        while (a >= 1 || b >= 1) {
            if (a >= b) {
                b++;
                a -= 2;
            } else {
                a++;
                b -= 2;
            }
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }
            c++;
        }
        cout << c << endl;
    }
    return 0;
}

void swap(int a, int b) {
    int t = b;
    b = a;
    a = t;
}

void debug(vector<int> obj) {
    for (int i = 0; i < obj.size(); i++) {
        cerr << obj[i] << " ";
    }
    cerr << endl;
}

// //End of Code.
