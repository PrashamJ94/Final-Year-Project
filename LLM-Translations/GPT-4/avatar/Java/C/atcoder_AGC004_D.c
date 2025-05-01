#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int k, answer = 0;
bool isCalculate = false;

typedef struct {
    int *array;
    int size;
} List;

typedef struct {
    List *lists;
    int size;
} ArrayList;

void add(List *l, int value) {
    l->array = realloc(l->array, (l->size + 1) * sizeof(int));
    l->array[l->size] = value;
    l->size++;
}

ArrayList createArrayList(int n) {
    ArrayList al;
    al.lists = malloc(n * sizeof(List));
    al.size = n;
    for (int i = 0; i < n; i++) {
        al.lists[i].array = NULL;
        al.lists[i].size = 0;
    }
    return al;
}

void initialize(int n, int _k, int *as, ArrayList *al) {
    k = _k;
    for (int i = 0; i < n; i++) {
        int j = as[i] - 1;
        if (i > 0) {
            add(&al->lists[j], i);
        } else if (j > 0) {
            answer++;
        }
    }
}

int dfs(ArrayList *al, int a, int pre) {
    int h = 0;
    for (int i = 0; i < al->lists[a].size; i++) {
        int index = al->lists[a].array[i];
        h = (h > dfs(al, index, a)) ? h : dfs(al, index, a);
    }
    if (pre > 0 && h == k - 1) {
        h = 0;
        answer++;
    } else {
        h++;
    }
    return h;
}

int calculate(ArrayList *al) {
    if (!isCalculate) {
        dfs(al, 0, 0);
        isCalculate = true;
    }
    return answer;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *as = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    ArrayList al = createArrayList(n);
    initialize(n, k, as, &al);
    printf("%d\n", calculate(&al));

    for (int i = 0; i < n; i++) {
        free(al.lists[i].array);
    }
    free(al.lists);
    free(as);

    return 0;
}
// //End of Code.
