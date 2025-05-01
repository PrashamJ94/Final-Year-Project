
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    
    char *S[N];
    for(int i = 0; i < N; i++) {
        S[i] = malloc(100 * sizeof(char));
        scanf("%s", S[i]);
    }

    char march[5] = {'M', 'A', 'R', 'C', 'H'};
    int march_lis[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            if(S[i][0] == march[j]) {
                march_lis[j]++;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            for(int k = j + 1; k < 5; k++) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    printf("%lld\n", ans);

    for(int i = 0; i < N; i++) {
        free(S[i]);
    }

    return 0;
}

// End of Code

//The C language does not have some functions that Python has, such as combinations, list comprehensions, and the 'in' keyword, so we must implement these functionalities manually. Also, since C does not have garbage collection, we must manually free the memory we allocated with malloc.
