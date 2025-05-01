#include <iostream>
#include <string>
using namespace std;

char solve(char c) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find(c);
    return a[i + 1];
}

int main() {
    char c;
    cin >> c;
    cout << solve(c) << endl;
    return 0;
}
// End of Code
