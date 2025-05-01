#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int>> mat(N, vector<int>(D));

    for(int d = 0; d < N; d++) {
        for(int i = 0; i < D; i++) {
            cin >> mat[d][i];
        }
    }

    int c = 0;
    for(int i = 0; i < mat.size() - 1; i++) {
        for(int j = i + 1; j < mat.size(); j++) {
            double dist = 0;
            for(int k = 0; k < D; k++) {
                dist += (mat[i][k] - mat[j][k]) * (mat[i][k] - mat[j][k]);
            }
            dist = sqrt(dist);
            if(int(dist) == dist) {
                c++;
            }
        }
    }

    cout << c << endl;

    return 0;
}
// 
