
#include <stdio.h>

int main() {
    char LUCKY[] = "abcd";
    int n, i;
    char s[100]; // Assuming the maximum length of string s is 100
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        s[i] = LUCKY[i % 4];
    }
    
    s[i] = '\0'; // End of string
    printf("%s", s);
    
    return 0;
}

// End of Code
