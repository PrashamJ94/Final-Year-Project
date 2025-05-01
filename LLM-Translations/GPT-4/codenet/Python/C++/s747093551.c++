#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N), y(M);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> y[i];
    }
    cout << (max(*max_element(x.begin(), x.end()), X) < min(*min_element(y.begin(), y.end()), Y) ? "No War" : "War") << endl;
    return 0;
} // 
