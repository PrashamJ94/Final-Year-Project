#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[n][4];
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    char *mark[] = {"S", "H", "C", "D"};
    for (int m = 0; m < 4; m++) {
        for (int i = 1; i <= 13; i++) {
            char st[4];
            sprintf(st, "%s %d", mark[m], i);
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (strcmp(st, str[j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%s\n", st);
            }
        }
    }

    return 0;
}
// 
