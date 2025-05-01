#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int find_index(int* arr, int n, int* perm) {
    int index = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i + 1; j < n; j++) {
            if(perm[i] > perm[j])
                cnt++;
        }
        index += cnt * factorial(n - i - 1);
    }
    return index;
}

int main() {
    int n;
    scanf("%d", &n);

    int* p = (int*) malloc(n * sizeof(int));
    int* q = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    int pn = find_index(p, n, p);
    int qn = find_index(p, n, q);

    printf("%d\n", abs(pn - qn));

    free(p);
    free(q);

    return 0;
}

// End of Code

