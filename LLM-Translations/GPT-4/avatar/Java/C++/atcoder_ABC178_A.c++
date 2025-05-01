#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    bool boolValue = x == 1 ? true : false;
    int result = !boolValue ? 1 : 0;
    cout << result << endl;
    return 0;
} // //End of Code
