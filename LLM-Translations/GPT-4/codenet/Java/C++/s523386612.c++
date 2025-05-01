#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> count(t + 1, 0);
    for (int i = 2; i < t + 1; i++) {
        int temp;
        cin >> temp;
        count[temp]++;
    }
    for (int i = 1; i < t + 1; i++) {
        cout << count[i] << endl;
    }
    return 0;
}
// 
