#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int result = max({a*c, b*d, a*d, b*c});

    cout << result << "\n";

    return 0;
} //End of Code
