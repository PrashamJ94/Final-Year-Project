#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    char inputStrings[n][100];
    for(int i = 0; i < n; i++) {
        scanf("%s", inputStrings[i]);
    }

    int uniqueCount = 0;
    bool unique;

    for(int i = 0; i < n; i++) {
        unique = true;

        for(int j = 0; j < i; j++) {
            if(strcmp(inputStrings[i], inputStrings[j]) == 0) {
                unique = false;
                break;
            }
        }

        if(unique) {
            uniqueCount++;
        }
    }

    printf("%d\n", uniqueCount);

    return 0;
} // 
