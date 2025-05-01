#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 100000; i++) {
        if (i * i > n) {
            cout << (i - 1) * (i - 1) << endl;
            exit(0);
        }
    }
    return 0;
}
// 
