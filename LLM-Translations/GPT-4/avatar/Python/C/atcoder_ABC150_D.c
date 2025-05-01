#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);
    int num_set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_set[i]);
    }
    
    int two_times_set[30];
    for (int i = 0; i < 30; i++) {
        two_times_set[i] = 0;
    }
    
    bool more_than_one = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 30; j++) {
            num_set[i] /= 2;
            if (num_set[i] % 2 != 0) {
                two_times_set[j] = 1;
                break;
            }
        }
        
        int count = 0;
        for (int k = 0; k < 30; k++) {
            if (two_times_set[k] == 1) {
                count++;
            }
        }
        
        if (count != 1) {
            printf("0\n");
            more_than_one = true;
            break;
        }
    }
    
    if (!more_than_one) {
        int lcm = num_set[0];
        for (int i = 1; i < n; i++) {
            lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);
        }
        printf("%d\n", (num - lcm / 2) / lcm + 1);
    }
    
    return 0;
}
// End of Code
