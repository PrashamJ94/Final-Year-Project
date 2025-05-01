#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N), C(N), List(1,0);
    int ans = 0, X = 0, Y = 0;

    for(int i = 0; i < N; i++)
        cin >> V[i];

    for(int i = 0; i < N; i++)
        cin >> C[i];

    for(int i = 0; i < N; i++) {
        if(V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            List.push_back(X - Y);
        }
    }
    
    cout << accumulate(List.begin(), List.end(), 0) << endl;

    return 0;
} // End of Code
