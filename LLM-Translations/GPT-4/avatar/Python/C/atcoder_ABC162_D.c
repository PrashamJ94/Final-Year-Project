#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(int n, char* s) {
    int rNum = 0, gNum = 0, bNum = 0, sum = 0, i, step;
    for(i = 0; i < n; i++) {
        if(s[i] == 'R') rNum++;
        else if(s[i] == 'G') gNum++;
        else if(s[i] == 'B') bNum++;
    }
    for(step = 1; step <= ceil(n / 2.0); step++) {
        for(i = 0; i < n - 2 * step; i++) {
            if((s[i] == 'R' && s[i + step] == 'G' && s[i + step * 2] == 'B') ||
               (s[i] == 'R' && s[i + step] == 'B' && s[i + step * 2] == 'G') ||
               (s[i] == 'B' && s[i + step] == 'R' && s[i + step * 2] == 'G') ||
               (s[i] == 'B' && s[i + step] == 'G' && s[i + step * 2] == 'R') ||
               (s[i] == 'G' && s[i + step] == 'B' && s[i + step * 2] == 'R') ||
               (s[i] == 'G' && s[i + step] == 'R' && s[i + step * 2] == 'B')) {
                sum++;
            }
        }
    }
    printf("%d\n", rNum * gNum * bNum - sum);
}

int main() {
    int N;
    char S[1000];
    scanf("%d", &N);
    scanf("%s", S);
    calculate(N, S);
    return 0;
}
// End of Code
