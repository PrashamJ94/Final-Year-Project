#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, s1 = 0, s2 = 0, i, j = 0, flag = 0, dif = 0;
    scanf("%d", &n);
    char ch[n];
    
    for (i = 0; i < n; i++) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        int temp1 = s1 + x;
        int temp2 = s2 + y;
        
        if (abs(temp1 - s2) <= 500) {
            s1 += x;
            ch[j++] = 'A';
            continue;
        }
        if (abs(temp2 - s1) <= 500) {
            s2 += y;
            ch[j++] = 'G';
            continue;
        }
        flag = 1;
        break;
    }
    
    if (flag == 1)
        printf("-1\n");
    else {
        ch[j] = '\0';
        printf("%s\n", ch);
    }
    
    return 0;
}

// //End of Code.
