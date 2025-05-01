
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char sentence[1000];
    scanf(" %[^\n]", sentence);
    char* s = strtok(sentence, ".?!");
    int ans = 1, sumL = 0, L;
    while(s != NULL) {
        s = strcat(s, ".");
        L = strlen(s);
        if(L > 1) {
            if(L > n) {
                printf("Impossible\n");
                exit(0);
            }
            if(sumL + L + (sumL > 0) > n) {
                ans += 1;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
        s = strtok(NULL, ".?!");
    }
    printf("%d\n", ans);
    return 0;
}
/* End of Code */

