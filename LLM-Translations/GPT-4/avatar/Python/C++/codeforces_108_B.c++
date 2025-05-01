#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s() {
    int size;
    cin >> size;
    vector<int> a(size);
    
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 1; i < size; i++){
        if(a[i] != a[i - 1] && a[i] < a[i - 1] * 2){
            return "YES";
        }
    }
    return "NO";
}

int main() {
    cout << s() << endl;
    return 0;
}
// End of Code
