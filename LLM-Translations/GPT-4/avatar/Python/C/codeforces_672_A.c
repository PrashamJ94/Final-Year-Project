#include <stdio.h>

int main() {
    int li[1000], ind = 0;
    
    for (int i = 1; i < 371; i++) {
        int temp[3], p = i, q = i, count = 0;
        
        while (p != 0) {
            p /= 10;
            count++;
        }
        
        if (count == 1) {
            li[ind++] = i;
        }
        
        if (count == 2) {
            int tempIndex = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[tempIndex++] = x;
            }
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
        
        if (count == 3) {
            int tempIndex = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[tempIndex++] = x;
            }
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
    }
    
    ind -= 2;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d\n", li[n - 1]);

    return 0;
}

// End of Code
