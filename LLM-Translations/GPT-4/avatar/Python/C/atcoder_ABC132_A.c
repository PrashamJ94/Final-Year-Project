#include <stdio.h>
#include <string.h>

int main () {
    char S[100];
    scanf("%s", S);
    
    int c[26] = {0};
    
    for (int i = 0; i < strlen(S); i++) {
        c[S[i] - 'a']++;
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 2) {
            count++;
        } else if (c[i] != 0) {
            printf("No\n");
            return 0;
        }
    }
    
    if (count == 2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
} // End of Code
