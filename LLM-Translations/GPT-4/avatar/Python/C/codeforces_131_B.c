
#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    int w[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    qsort(w, n, sizeof(int), cmpfunc);

    int c = 0;
    for(i = 0; i < n; i++) {
        if(w[i] == 0) {
            for(j = i+1; j < n && w[j] == 0; j++);
            c += (j - i) * (j - i - 1);
            i = j - 1;
        } else {
            for(j = i+1; j < n && w[j] == w[i]; j++);
            int k = 0;
            while(-w[i] == w[k]) k++;
            if(k < n && -w[i] == w[k]) {
                for(; k < n && -w[i] == w[k]; k++);
                c += (j - i) * (k - i);
                i = j - 1;
            }
        }
    }
    printf("%d\n", c/2);
    return 0;
}
// End of Code
