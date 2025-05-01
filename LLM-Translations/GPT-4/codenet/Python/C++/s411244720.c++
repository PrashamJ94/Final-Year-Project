#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, K, d;
    cin >> N >> K;
    set<int> S;
    for (int i = 0; i < K; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            int A;
            cin >> A;
            S.insert(A);
        }
    }
    cout << N - S.size() << endl;
    return 0;
}
// 
