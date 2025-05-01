#include <stdio.h>
#include <limits.h>

int maxInt(int x, int a[], int m);
int minInt(int y, int b[], int n);
void checkWar(int a, int b);

int main() {
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);

    int a[m];
    for(int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    int b[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int x_max = maxInt(x, a, m);
    int y_min = minInt(y, b, n);
    checkWar(x_max, y_min);

    return 0;
}

int maxInt(int x, int a[], int m){
    int bignum = x;
    for(int i = 0; i < m; i++) {
        bignum = (bignum > a[i]) ? bignum : a[i];
    }
    return bignum;
}

int minInt(int y, int b[], int n){
    int smallnum = y;
    for(int i = 0; i < n; i++) {
        smallnum = (smallnum < b[i]) ? smallnum : b[i];
    }
    return smallnum;
}

void checkWar(int a, int b){
    if(a >= b) {
        printf("War\n");
    } else {
        printf("No War\n");
    }
}
/*  */
