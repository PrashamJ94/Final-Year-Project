#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<vector<int>>> m(4, vector<vector<int>>(3, vector<int>(10, 0)));
    int b, f, r, v;
    
    for(int i = 0; i < N; ++i) {
        cin >> b >> f >> r >> v;
        m[b-1][f-1][r-1] += v;
    }
    
    string line;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 10; ++k) {
                line += ' ' + to_string(m[i][j][k]);
            }
            cout << line << endl;
            line = "";
        }
        if(i < 3) {
            cout << "####################" << endl;
        }
    }
    
    return 0;
}
// 
