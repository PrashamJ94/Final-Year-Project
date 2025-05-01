#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    int a, b, digit;
    stringstream sb;
    while (cin >> a >> b) {
        digit = (int) log10(a + b) + 1;
        sb << digit << '\n';
    }
    cout << sb.str();
    return 0;
}
// 
