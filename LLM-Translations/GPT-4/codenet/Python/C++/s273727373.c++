
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int count = 1;
    for (int i : A) {
        B[i - 1] = count;
        count++;
    }

    for (int i : B) {
        cout << i << " ";
    }

    return 0;
}
// 


