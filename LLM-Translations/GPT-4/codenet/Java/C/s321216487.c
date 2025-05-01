#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    scanf("%s", S);
    
    char begin[100];
    char end[100];
    char answer[100];
    
    int length = strlen(S);

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            strncpy(begin, S, i);
            begin[i] = '\0';
            strcpy(end, S + j);
            strcpy(answer, begin);
            strcat(answer, end);

            if(strcmp(answer, "keyence") == 0) {
                printf("YES\n");
                return 0;
            } else if(strcmp(begin, "keyence") == 0) {
                printf("YES\n");
                return 0;
            } else if(strcmp(end, "keyence") == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }
    
    printf("NO\n");
    return 0;
}

// 
