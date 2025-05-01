#include <stdio.h>
#include <stdbool.h>
#include <string.h>

long long powP[1005], powQ[1005];
char a[1005][1005];
long long hashRow[1005][1005], hashCol[1005][1005];

int main() {
    int n;
    scanf("%d", &n);

    long long P = 37, Q = 47;
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
            }
            ans += ok ? 1 : 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// 
