#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> array(n);
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    string a = array[0];
    cnt++;
    for(int i = 0; i < n; i++) {
        if(a == array[i]) {
        } else {
            cnt++;
        }
        a = array[i];
    }
    cout << cnt << endl;
    return 0;
}
// 
