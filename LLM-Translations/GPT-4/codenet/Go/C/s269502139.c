
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int32_t key;
    struct node *prev;
    struct node *next;
} node;

void rPrint(node *n, char *buf) {
    char temp[32];
    sprintf(temp, "%d", n->key);
    strcat(buf, temp);
    if (n->next != NULL) {
        strcat(buf, " ");
        rPrint(n->next, buf);
    }
}

void deleteNode(node **first, node **last, node *n) {
    if (n->prev != NULL && n->next != NULL) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return;
    }

    if (n->next == NULL && n->prev == NULL) {
        *first = NULL;
        *last = NULL;
        return;
    }

    if (n->prev == NULL) {
        *first = n->next;
        n->next->prev = NULL;
    }

    if (n->next == NULL) {
        *last = n->prev;
        n->prev->next = NULL;
    }
}

node *initNode(int32_t key) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int main() {
    char cmd[32];
    node *first = NULL, *last = NULL;

    while (fgets(cmd, sizeof(cmd), stdin)) {
        strtok(cmd, "\n");
        if (strcmp(cmd, "deleteFirst") == 0) {
            deleteNode(&first, &last, first);
        } else if (strcmp(cmd, "deleteLast") == 0) {
            deleteNode(&first, &last, last);
        } else {
            char *splitCmd = strtok(cmd, " ");
            int32_t key = atoi(strtok(NULL, " "));
            if (strcmp(splitCmd, "delete") == 0) {
                for (node *n = first; n != NULL; n = n->next) {
                    if (n->key == key) {
                        deleteNode(&first, &last, n);
                        break;
                    }
                }
            } else if (strcmp(splitCmd, "insert") == 0) {
                node *n = initNode(key);
                n->next = first;
                if (first != NULL) {
                    first->prev = n;
                }

                first = n;
                if (last == NULL) {
                    last = n;
                }
            }
        }
    }

    char buf[1024] = "";
    rPrint(first, buf);
    printf("%s\n", buf);
    return 0;
}


