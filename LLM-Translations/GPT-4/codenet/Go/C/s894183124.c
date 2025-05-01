#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[101];
    scanf("%d", &n);
    scanf("%s", s);
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

// 
