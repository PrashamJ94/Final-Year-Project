
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
} KeyValuePair;

typedef struct {
    KeyValuePair *data;
    int count;
    int capacity;
} HashMap;

void initHashMap(HashMap *map, int capacity) {
    map->data = (KeyValuePair *) malloc(sizeof(KeyValuePair) * capacity);
    map->count = 0;
    map->capacity = capacity;
}

void freeHashMap(HashMap *map) {
    free(map->data);
}

int getOrDefault(HashMap *map, int key, int defaultValue) {
    for (int i = 0; i < map->count; i++) {
        if (map->data[i].key == key) {
            return map->data[i].value;
        }
    }
    return defaultValue;
}

void merge(HashMap *map, int key, int value) {
    for (int i = 0; i < map->count; i++) {
        if (map->data[i].key == key) {
            map->data[i].value += value;
            return;
        }
    }
    if (map->count == map->capacity) {
        map->capacity *= 2;
        map->data = (KeyValuePair *) realloc(map->data, sizeof(KeyValuePair) * map->capacity);
    }
    map->data[map->count].key = key;
    map->data[map->count].value = value;
    map->count++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    HashMap dp;
    initHashMap(&dp, 10);
    long ans = 0;
    int base = 0;
    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        merge(&dp, (base + a[i]) % m, 1);
        ans += getOrDefault(&dp, base, 0);
    }
    printf("%ld\n", ans);
    freeHashMap(&dp);

    return 0;
}

// //End of Code
