#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

ArrayList *createArrayList(int capacity) {
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    list->array = (int *) malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *) realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = value;
}

int get(ArrayList *list, int index) {
    return list->array[index];
}

ArrayList **g;
int maxMatching(int v, int p) {
    int a = 0, o = 0;
    for (int i = 0; i < g[v]->size; ++i) {
        int w = get(g[v], i);
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + (o > 0 ? 1 : 0) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    g = (ArrayList **) malloc(n * sizeof(ArrayList *));
    for (int i = 0; i < n; ++i) {
        g[i] = createArrayList(10);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        add(g[a], b);
        add(g[b], a);
    }
    int m = maxMatching(0, -1) / 2;
    printf("%s\n", 2 * m == n ? "Second" : "First");
    
    for(int i = 0; i < n; ++i) {
        free(g[i]->array);
        free(g[i]);
    }
    free(g);
    return 0;
}

// //End of Code
