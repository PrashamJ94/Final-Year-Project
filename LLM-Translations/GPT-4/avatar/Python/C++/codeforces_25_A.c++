#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> list[i];
        list[i] %= 2;
        sum += list[i];
    }
    if(sum == 1) {
        for(int i = 0; i < n; i++) {
            if(list[i] == 1) {
                cout << i+1 << endl;
                break;
            }
        }
    } else {
        for(int i = 0; i < n; i++) {
            if(list[i] == 0) {
                cout << i+1 << endl;
                break;
            }
        }
    }
    return 0;
} // End of Code
