
#include <stdio.h>
#include <string.h>

int main() {
    char S[1000];
    scanf("%s", S);
    int score = 0;
    for(int i = 0; i < strlen(S); i++) {
        char my = i % 2 == 0 ? 'g' : 'p';
        char his = S[i];
        if(my != his) {
            score += my == 'p' ? 1 : -1;
        }
    }
    printf("%d\n", score);
    return 0;
}

/* //End of Code */

