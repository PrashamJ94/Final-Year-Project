#include <iostream>
using namespace std;

int func(int a) {
    int digits;
    int temp = a;
    int result = 0;
    while (temp != 0) {
        digits = temp % 10;
        temp = temp / 10;
        result += digits;
    }
    if (result == 1) {
        cout << "10" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}

int main() {
    int a;
    cin >> a;
    func(a);
    return 0;
}
// 
