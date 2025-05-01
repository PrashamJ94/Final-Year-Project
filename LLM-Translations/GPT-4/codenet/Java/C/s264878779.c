#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[20];
    scanf("%s", s);
    int n = strlen(s);
    long ans = 0;
    for(int mask = 0 ; mask < 1<<(n - 1) ; mask++) {
        long sum = 0;
        char x[40] = "";
        strncat(x, &s[0], 1);
        for(int i = 0 ; i < n - 1 ; i++) {
            if((mask & (1 << i)) >= 1) {
                strcat(x, "+");
                strncat(x, &s[i + 1], 1);
            } else {
                strncat(x, &s[i + 1], 1);
            }
        }
        char *split = strtok(x, "+");
        while(split != NULL) {
            sum += strtol(split, NULL, 10);
            split = strtok(NULL, "+");
        }
        ans += sum;
    }
    printf("%ld\n", ans);
    return 0;
}

// 
