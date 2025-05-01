#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // A + B
    int x = a + b;
    // A - B
    x = max(x, a - b);
    // A * B
    x = max(x, a * b);
    cout << x << endl;

    return 0;
} // 
