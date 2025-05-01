#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char inputed[1000];
    int ans;

    while(1) {

        fgets(inputed, sizeof(inputed), stdin);
        if(strlen(inputed) == 2 && inputed[0] == '0') break;

        ans = 0;
        for(int i = 0; i < strlen(inputed) - 1; i++) {
            ans += inputed[i] - '0';
        }

        printf("%d\n", ans);
    }

    return 0;
}

// 
