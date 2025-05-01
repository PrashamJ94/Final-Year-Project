#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    struct node *next;
} node;

typedef struct hashtable {
    int size;
    struct node **table;
} hashtable;

// Create a new hashtable
hashtable *create_hashtable(int size) {
    hashtable *new_table;

    if (size < 1) return NULL;

    if ((new_table = malloc(sizeof(hashtable))) == NULL) {
        return NULL;
    }

    if ((new_table->table = malloc(sizeof(node *) * size)) == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        new_table->table[i] = NULL;
    }

    new_table->size = size;

    return new_table;
}

// Hash function
unsigned int hash(hashtable *hashtable, char *str) {
    unsigned int hashval = 0;

    for (; *str != '\0'; str++) {
        hashval = *str + (hashval << 5) - hashval;
    }

    return hashval % hashtable->size;
}

// Insert key into hashtable
node *insert(hashtable *hashtable, char *key) {
    node *new_node;
    unsigned int hashval = hash(hashtable, key);

    if ((new_node = malloc(sizeof(node))) == NULL) {
        return NULL;
    }

    new_node->key = strdup(key);
    new_node->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_node;

    return new_node;
}

// Search for key in hashtable
node *search(hashtable *hashtable, char *key) {
    unsigned int hashval = hash(hashtable, key);
    node *list = hashtable->table[hashval];

    while (list != NULL) {
        if (strcmp(key, list->key) == 0) {
            return list;
        }
        list = list->next;
    }

    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    hashtable *map = create_hashtable(n);
    char str[1000];

    for (int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;

        if (search(map, str) == NULL) {
            insert(map, str);
        }
    }

    int count = 0;
    for (int i = 0; i < map->size; i++) {
        node *list = map->table[i];
        while (list != NULL) {
            count++;
            list = list->next;
        }
    }

    printf("%d\n", count);

    return 0;
}

// 
