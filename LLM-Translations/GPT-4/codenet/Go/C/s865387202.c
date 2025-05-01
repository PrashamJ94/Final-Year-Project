
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int prefecture;
    int position;
    int year;
} city;

int compare(const void *a, const void *b) {
    city *cityA = (city *)a;
    city *cityB = (city *)b;
    return cityA->year - cityB->year;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    city cities[m];

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        cities[i].prefecture = x;
        cities[i].year = y;
        cities[i].position = i;
    }

    qsort(cities, m, sizeof(city), compare);

    char results[m][13];
    int count[n + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < m; i++) {
        int prefecture = cities[i].prefecture;
        int idx = ++count[prefecture];
        snprintf(results[cities[i].position], 13, "%06d%06d", prefecture, idx);
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}

// 
