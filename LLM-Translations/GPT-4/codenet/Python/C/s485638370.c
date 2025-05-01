#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);
    bool found = false;

    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '9') {
            found = true;
            break;
        }
    }

    if (found) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
} // 
