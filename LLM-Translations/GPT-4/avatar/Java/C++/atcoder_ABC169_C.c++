#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long a;
    string b;
    cin >> a >> b;

    b.erase(remove(b.begin(), b.end(), '.'), b.end());
    int bInt = stoi(b);

    long long result = (a * bInt) / 100;
    cout << result << endl;

    return 0;
}

// //End of Code
