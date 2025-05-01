#include<bits/stdc++.h>
using namespace std;

double solve(int N, vector<int> x, vector<int> y) {
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    double total_distance = 0.0;
    do{
        for(int i=0; i<N-1; i++) {
            int f = indices[i];
            int t = indices[i+1];
            double distance = sqrt(pow(x[t]-x[f], 2) + pow(y[t]-y[f], 2));
            total_distance += distance;
        }
    } while(next_permutation(indices.begin(), indices.end()));
    double result = total_distance / tgamma(N+1);
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    double result = solve(N, x, y);
    cout << result << endl;
    return 0;
}
// End of Code.
