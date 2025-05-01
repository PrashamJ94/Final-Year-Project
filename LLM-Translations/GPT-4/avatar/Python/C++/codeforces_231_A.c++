#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a + b > 1) {
            c = c + 1;
        }
    }
    cout << c;
    return 0;
} // End of Code
