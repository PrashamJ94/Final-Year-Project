#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n;
    int minN;
    cin >> minN;
    minN -= 1;
    for(int i = 0; i < n - 1; i++) {
        cin >> h;
        if(minN == h) {
            minN = h;
        } else if(minN == h - 1) {
            minN = h - 1;
        } else if(minN < h - 1) {
            minN = h - 1;
        } else if(minN > h) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

// 
