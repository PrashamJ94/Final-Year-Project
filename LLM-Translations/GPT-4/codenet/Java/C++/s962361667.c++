#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> values(w);
    for (int i = 0; i < values.size(); i++) {
        values[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int x = 0;
        string str;
        cin >> str;
        stringstream ss(str);
        string ab;
        getline(ss, ab, ',');
        int a = stoi(ab) - 1;
        getline(ss, ab, ',');
        int b = stoi(ab) - 1;
        x = values[a];
        values[a] = values[b];
        values[b] = x;
    }
    for(int i = 0; i < w; i++){
        cout << values[i] << endl;
    }
    return 0;
}
// 
