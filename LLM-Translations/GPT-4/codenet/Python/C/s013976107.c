#include <stdio.h>
#include <string.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    char S[100];
    scanf("%s", S);
    int count = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '-') {
            count++;
        }
    }
    if (S[A] == '-' && count == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
} // 
