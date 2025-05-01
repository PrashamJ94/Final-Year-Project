
#include <stdio.h>
#include <stdbool.h>

bool help(int a, int b, int *l) {
    int tot[12][12];
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    for(int i = 0; i < a; i++) {
        int sum = 0;
        for(int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if(sum == b)
            return true;
    }
    return false;
}

void solve() {
    int tot[12][2], k = 0;
    char x[13];
    int s[12];
    scanf("%s", x);
    for(int i = 0; i < 12; i++) {
        if(x[i] == 'O')
            s[i] = 0;
        else
            s[i] = 1;
    }
    for(int i = 1; i <= 12; i++) {
        if(12 % i == 0) {
            if(help(i, 12 / i, s)) {
                tot[k][0] = 12 / i;
                tot[k][1] = i;
                k++;
            }
        }
    }
    printf("%d ", k);
    for(int i = 0; i < k; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

// End of Code
