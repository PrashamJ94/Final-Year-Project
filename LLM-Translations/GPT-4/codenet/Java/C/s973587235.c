#include <stdio.h>

int main() {
    int n, i, h, minN;
    // Input an integer
    scanf("%d", &n);
    scanf("%d", &minN);
    minN = minN - 1;
    for(i = 0; i < n - 1; i++) {
        scanf("%d", &h);
        if(minN == h) {
            minN = h;
        } else if(minN == h - 1) {
            minN = h - 1;
        } else if(minN < h - 1) {
            minN = h - 1;
        } else if(minN > h) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
// 
