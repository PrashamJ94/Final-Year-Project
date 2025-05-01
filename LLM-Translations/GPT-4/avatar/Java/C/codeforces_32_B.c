#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char n[1000];
    scanf("%s", n);
    bool s = false;

    for(int i = 0; i < strlen(n); i++) {
        if(n[i] == '.') {
            if(s) {
                printf("%d", 1);
                s = false;
            } else {
                printf("%d", 0);
            }
        } else {
            if(s) {
                printf("%d", 2);
                s = false;
            } else {
                s = true;
            }
        }
    }

    return 0;
}
// //End of Code
