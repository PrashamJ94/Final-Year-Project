#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    char key[10];
    struct Node *next;
};

struct Node *createNode(const char *key) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, const char *key) {
    struct Node *newNode = createNode(key);
    newNode->next = *head;
    *head = newNode;
}

bool find(struct Node *head, const char *key) {
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    char str[10], com[13];
    struct Node *T = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", com, str);
        if (com[0] == 'i') {
            insert(&T, str);
        } else {
            if (find(T, str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    freeList(T);
    return 0;
}

// 
