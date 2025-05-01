#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int num_g = 0, num_p = 0;
    int score = 0;
    
    fgets(s, 100, stdin);
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                score = score;
                num_g += 1;
            }
        } else if (s[i] == 'p') {
            if (num_g - num_p > 0) {
                score = score;
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }
    printf("%d\n", score);
    return 0;
}
// End of Code
