#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    long N, min = 0, temp;
    scanf("%ld", &N);
    
    for (int i = 0; i < 5; i++) {
        scanf("%ld", &temp);
        if (i == 0) {
            min = temp;
        } else {
            min = (min < temp) ? min : temp;
        }
    }

    printf("%ld\n", (long) ceil((double) N / min) + 4);

    return 0;
}

// //End of Code
