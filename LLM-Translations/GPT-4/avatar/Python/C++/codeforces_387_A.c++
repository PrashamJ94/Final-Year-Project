#include <iostream>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    char ch;

    cin >> h1 >> ch >> m1;
    m1 += h1 * 60;

    cin >> h2 >> ch >> m2;
    m2 += h2 * 60;

    m2 = m1 - m2;
    m2 %= 1440;

    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
} // End of Code.
