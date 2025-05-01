#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a, b;
    while(cin >> a >> b) {
        if(a > b) {
            cout << "GREATER" << endl;
        }
        else if(a < b) {
            cout << "LESS" << endl;
        }
        else {
            cout << "EQUAL" << endl;
        }
    }
    return 0;
}
// 
