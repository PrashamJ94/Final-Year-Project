
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree_map.h"

int n;
int *a;
tree_map *s;

void set() {
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    s = tree_map_create();
}

bool isPossible(int k) {
    tree_map_clear(s);
    int current = 0;
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        if (ai <= current) {
            if (k == 1) return false;
            while (!tree_map_is_empty(s) && tree_map_last_key(s) >= ai) {
                tree_map_poll_last_entry(s);
            }
            int p = ai - 1;
            while (true) {
                if (p < 0) return false;
                int sp = tree_map_get_or_default(s, p, 0) + 1;
                tree_map_put(s, p, sp);
                if (sp == k) {
                    tree_map_remove(s, p);
                    p--;
                } else {
                    break;
                }
            }
        }
        current = ai;
    }
    return true;
}

int main() {
    set();
    int ng = 0;
    int ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
    tree_map_destroy(s);
    free(a);
    return 0;
}

//End of Code
