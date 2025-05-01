#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char **data;
    int size;
    int capacity;
} StringVector;

void StringVector_init(StringVector *vector) {
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

void StringVector_push_back(StringVector *vector, const char *str) {
    if (vector->size == vector->capacity) {
        vector->capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        vector->data = (char **)realloc(vector->data, vector->capacity * sizeof(char *));
    }
    vector->data[vector->size] = strdup(str);
    vector->size++;
}

void StringVector_free(StringVector *vector) {
    for (int i = 0; i < vector->size; i++) {
        free(vector->data[i]);
    }
    free(vector->data);
}

bool solve() {
    int maxsize = 0;
    int maxcnt = 0;
    int ans_num;
    int ans_num2;
    StringVector str_v;

    StringVector_init(&str_v);

    char in[1024];
    while (scanf("%s", in) != EOF) {
        StringVector_push_back(&str_v, in);
        if (maxsize < strlen(in)) {
            maxsize = strlen(in);
            ans_num = str_v.size - 1;
        }
    }
    for (int i = 0; i < str_v.size; i++) {
        int cnt = 0;
        for (int j = 0; j < str_v.size; j++) {
            if (strcmp(str_v.data[i], str_v.data[j]) == 0) cnt++;
        }
        if (maxcnt < cnt) {
            maxcnt = cnt;
            ans_num2 = i;
        }
    }

    printf("%s %s\n", str_v.data[ans_num2], str_v.data[ans_num]);

    StringVector_free(&str_v);

    return true;
}

int main() {
    solve();

    return 0;
}
/*  */
