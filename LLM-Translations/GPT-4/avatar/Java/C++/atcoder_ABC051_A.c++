#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    replace(a.begin(), a.end(), ',', ' ');
    cout << a << endl;
    return 0;
}
// //End of Code
