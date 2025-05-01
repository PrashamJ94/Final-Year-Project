#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    long sum = 0, ans, sum1;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    char s[n];
    scanf("%s", s);
    for(i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if(ch == 'B') sum += a[i];
    }
    ans = sum;
    sum1 = sum;
    for(i = 0; i < strlen(s); i++) {
        if(s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = (ans > sum1) ? ans : sum1;
    }
    sum1 = sum;
    for(i = strlen(s) - 1; i >= 0; i--) {
        if(s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = (ans > sum1) ? ans : sum1;
    }
    printf("%ld\n", ans);
    return 0;
}

// //End of Code
