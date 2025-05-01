Here is C equivalent of your Java code:


#include <stdio.h>
#include <stdlib.h>

int* colors;
typedef struct Point Point;
typedef struct Entry Entry;

struct Entry {
    Point* key;
    int value;
};

struct Point {
    int name;
    Entry** friends;
    int friendsSize;
};

void becomeFriend(Point* this, Point* p, int length) {
    this->friends[this->friendsSize] = malloc(sizeof(Entry));
    this->friends[this->friendsSize]->key = p;
    this->friends[this->friendsSize]->value = length;
    this->friendsSize++;
}

void dfs(Point* p, int length) {
    int alreadyKnown = colors[p->name] != -1;
    if (alreadyKnown) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    for (int i = 0; i < p->friendsSize; i++) {
        Point* friend = p->friends[i]->key;
        int length2 = p->friends[i]->value;
        dfs(friend, length + length2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n - 1;
    colors = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }
    Point** points = malloc(n * sizeof(Point*));
    for (int i = 0; i < n; i++) {
        points[i] = malloc(sizeof(Point));
        points[i]->name = i;
        points[i]->friends = malloc((n - 1) * sizeof(Entry*));
        points[i]->friendsSize = 0;
    }
    while (m-- > 0) {
        int me, you, length;
        scanf("%d %d %d", &me, &you, &length);
        me--;
        you--;
        becomeFriend(points[me], points[you], length);
        becomeFriend(points[you], points[me], length);
    }
    dfs(points[0], 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", colors[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(colors);
        for (int j = 0; j < points[i]->friendsSize; j++) {
            free(points[i]->friends[j]);
        }
        free(points[i]->friends);
        free(points[i]);
    }
    free(points);
    return 0;
}

/* //End of Code */
