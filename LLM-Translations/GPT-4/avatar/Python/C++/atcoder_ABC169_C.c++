#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    double b;
    string sa, sb;
    cin >> sa >> sb;

    a = stoi(sa);
    b = stod(sb) * 100 + 0.1;

    cout << (a * b) / 100;

    return 0;
} // End of Code
