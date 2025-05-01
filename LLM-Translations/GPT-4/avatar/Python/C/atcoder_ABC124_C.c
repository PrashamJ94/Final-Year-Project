#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000];
    scanf("%s", s);
    
    int even_0 = 0, even_1 = 0, odd_0 = 0, odd_1 = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                even_0++;
            } else {
                even_1++;
            }
        } else {
            if (s[i] == '0') {
                odd_0++;
            } else {
                odd_1++;
            }
        }
    }
    
    int result = len - (even_0 + odd_1);
    int alternative_result = len - (even_1 + odd_0);
    printf("%d\n", result < alternative_result ? result : alternative_result);
    
    return 0;
}
// End of Code
