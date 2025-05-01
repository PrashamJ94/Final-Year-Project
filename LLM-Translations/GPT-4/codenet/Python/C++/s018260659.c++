#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 1;
    while (cnt <= 9) {
        if (N % cnt == 0 && 1 <= N / cnt && N / cnt <= 9) {
            cout << "Yes" << endl;
            break;
        } else {
            cnt += 1;
        }
    }
    if (cnt == 10) {
        cout << "No" << endl;
    }
    return 0;
}
// 
