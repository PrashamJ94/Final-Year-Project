#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char s[100];
    int pmin = 1000, mmin = 0;
    scanf("%s", s);
    int len = strlen(s);
    s[len] = '0';
    s[len+1] = '\0';
    for (int i = strlen(s) - 1; i >= 0; i--) {
        int v = s[i] - '0';
        int npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        int nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    printf("%d\n", min(pmin, mmin));
    return 0;
}

//End of Code.
