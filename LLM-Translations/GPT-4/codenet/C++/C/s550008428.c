#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int s, x, d = 2;
    scanf("%d", &s);
    int size = 1000;
    int *a = (int*)malloc(size * sizeof(int));
    int count = 1;
    a[0] = s;

    while(1) {
        if(s % 2 == 0){
            x = s / 2;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if(a[i] == x) {
                    found = true;
                    break;
                }
            }
            if (found) {
                printf("%d\n", d);
                return 0;
            }
            if (count == size) {
                size *= 2;
                a = (int*)realloc(a, size * sizeof(int));
            }
            a[count++] = x;
        } else {
            x = 3 * s + 1;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if(a[i] == x) {
                    found = true;
                    break;
                }
            }
            if (found) {
                printf("%d\n", d);
                return 0;
            }
            if (count == size) {
                size *= 2;
                a = (int*)realloc(a, size * sizeof(int));
            }
            a[count++] = x;
        }
        s = x;
        d++;
    }

    printf("%d\n", d);

    free(a);
    return 0;
}
// 
