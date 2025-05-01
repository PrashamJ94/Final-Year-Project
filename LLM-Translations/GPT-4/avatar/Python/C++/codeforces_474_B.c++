#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> L;
    int num, r = 1, k;
    
    while(cin >> num) {
        for(int i = 0; i < num; i++) {
            L.push_back(r);
        }
        r++;
    }

    while(cin >> k) {
        cout << L[k - 1] << endl;
    }

    return 0;
}

// End of Code
