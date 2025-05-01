#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    string S1 = S, S3 = S;
    bool flag = false;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && S1[i] == 'R') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S1[i] == 'L') {
            flag = true;
            S1[i] = 'R';
        }
    }

    flag = false;
    count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && S3[i] == 'L') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S3[i] == 'R') {
            flag = true;
            S3[i] = 'L';
        }
    }

    count = 1;
    int sum1 = 0;
    char bef = S1[0];

    for (int i = 1; i < N; i++) {
        if (S1[i] == bef) {
            count++;
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = S1[i];
            sum1 += count - 1;
            count = 1;
        }
    }

    count = 1;
    int sum3 = 0;
    bef = S3[0];

    for (int i = 1; i < N; i++) {
        if (S3[i] == bef) {
            count++;
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = S3[i];
            sum3 += count - 1;
            count = 1;
        }
    }

    cout << max(sum1, sum3) << endl;

    return 0;
}

// //End of Code
