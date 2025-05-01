#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[100];
    scanf("%s", a);
    int count = 0;
    int prod = 1;
    char *token = strtok(a, "1");
    while (token != NULL) {
        for(int i = 0; i < strlen(token); i++) {
            if(token[i] == '0') {
                count++;
            }
        }
        prod *= (count + 1);
        count = 0;
        token = strtok(NULL, "1");
    }
    if(prod == 1) {
        printf("%d\n", 0);
    }
    else {
        printf("%d\n", prod);
    }
    return 0;
} // End of Code
