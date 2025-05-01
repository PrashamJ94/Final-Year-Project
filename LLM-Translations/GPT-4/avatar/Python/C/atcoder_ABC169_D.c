#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void prime_factorize(int n, int a[]) {
    int i=0;
    while(n%2 == 0) {
        a[i++] = 2;
        n /= 2;
    }
    for(int f=3; f*f<=n; f+=2) {
        if(n%f == 0) {
            a[i++] = f;
            n /= f;
        }
    }
    if(n != 1) {
        a[i++] = n;
    }
    a[i] = -1;
}

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) {
        printf("0\n");
        return 0;
    }
    int a[100];
    prime_factorize(n, a);
    int ans = 0;
    for(int i=0; a[i]!=-1; i++) {
        int x = a[i];
        for(int j=1; j<99999999; j++) {
            if(x >= j) {
                x -= j;
                ans++;
            } else {
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
