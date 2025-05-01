#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[100];
    fgets(a, 100, stdin);
    char vo[] = { 'a' , 'e' , 'i' , 'o' , 'u' , 'y' , 'A' , 'E' , 'I' , 'O' , 'U' , 'Y' };
    int found = 0;
    for(int i = strlen(a) - 2; i >= 0; i--) {
        if(a[i] == ' ' || a[i] == '?') {
            continue;
        }
        else {
            for(int j = 0; j < 12; j++) {
                if(a[i] == vo[j]) {
                    found = 1;
                    break;
                }
            }
            if(found) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            break;
        }
    }
    return 0;
} // End of Code
