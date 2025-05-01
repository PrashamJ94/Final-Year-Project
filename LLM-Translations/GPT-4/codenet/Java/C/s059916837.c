#include <stdio.h>
#include <string.h>
#include <limits.h>

int find(const char *a, const char *b, int len);

int main() {
    char S[1001], T[1001];
    scanf("%s", S);
    scanf("%s", T);
    int min = INT_MAX;
    for(int i = 0; i <= strlen(S) - strlen(T); i++){
        min = (min < find(S + i, T, strlen(T))) ? min : find(S + i, T, strlen(T));
    }
    if(min != INT_MAX){
        printf("%d\n", min);
    } else {
        printf("%lu\n", strlen(T));
    }
    return 0;
}

int find(const char *a, const char *b, int len) {
    int calc = 0;
    for(int x = 0; x < len; x++) {
        if(a[x] != b[x]) {
            calc++;
        }
    }
    return calc;
}

/*  */
