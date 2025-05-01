#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int lista[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    for(i = 0; i < n; i++) {
        if(i == 0) {
            printf("%d %d\n", lista[i+1] - lista[i], lista[n-1] - lista[i]);
            continue;
        } 
        else if(i == n - 1) {
            printf("%d %d\n", lista[n-1] - lista[n-2], lista[n-1] - lista[0]);
            continue;
        }
        else if(lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            printf("%d ", lista[i + 1] - lista[i]);
        }
        else {
            printf("%d ", lista[i] - lista[i - 1]);
        }
        if(lista[n - 1] - lista[i] > lista[i] - lista[0]) {
            printf("%d\n", lista[n - 1] - lista[i]);
        }
        else {
            printf("%d\n", lista[i] - lista[0]);
        }
    }
    
    return 0;
} // End of Code
