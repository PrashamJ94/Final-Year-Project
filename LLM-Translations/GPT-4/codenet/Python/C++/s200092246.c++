#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans[2];

    for (int i = 1; i <= N; ++i) {
        if ((i * (i + 1)) / 2 < N) {
            continue;
        } else {
            ans[0] = i - 1;
            ans[1] = ((i * (i + 1)) / 2) - N;
            break;
        }
    }
    for (int i = 0; i <= ans[0]; ++i) {
        if (i + 1 != ans[1]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
// 
