#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int m;
    int e;
} Menu;

int compare(const void* a, const void* b) {
    Menu *menuA = (Menu *)a;
    Menu *menuB = (Menu *)b;
    return menuA->e - menuB->e;
}

int main() {
    Menu menu[5];
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &menu[i].m);
        menu[i].e = menu[i].m % 10;
        if(menu[i].e == 0) {
            menu[i].e = 10;
        }
    }
    qsort(menu, 5, sizeof(Menu), compare);
    for(int i = 1; i < 5; i++) {
        ans += ((menu[i].m + 9) / 10) * 10;
    }
    printf("%d", ans + menu[0].m);
    return 0;
}
/* End of Code */


//Note that in C, array sorting is typically done using the `qsort` function, which requires a custom comparator function to dictate the sorting order. In this case, the `compare` function is used to sort the `menu` array based on the `e` value. The `math.ceil` function in Python is replaced by `(menu[i].m + 9) / 10` in C to round up to the nearest 10.
