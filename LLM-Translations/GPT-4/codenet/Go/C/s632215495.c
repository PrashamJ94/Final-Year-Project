#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
} node;

typedef struct tree {
    node* root;
} tree;

void insert(tree* t, int key) {
    if (t->root == NULL) {
        t->root = (node*)malloc(sizeof(node));
        t->root->key = key;
        t->root->parent = NULL;
        t->root->left = NULL;
        t->root->right = NULL;
        return;
    }

    node* currentNode;
    node* prevNode;
    currentNode = t->root;
    while (currentNode != NULL) {
        prevNode = currentNode;
        if (currentNode->key < key) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->parent = prevNode;
    newNode->left = NULL;
    newNode->right = NULL;
    if (prevNode->key < key) {
        prevNode->right = newNode;
    } else {
        prevNode->left = newNode;
    }
}

void visitPreorder(node* n, int* acc, int* size) {
    if (n == NULL) {
        return;
    }
    acc[*size] = n->key;
    (*size)++;
    if (n->left != NULL) {
        visitPreorder(n->left, acc, size);
    }
    if (n->right != NULL) {
        visitPreorder(n->right, acc, size);
    }
}

void visitInorder(node* n, int* acc, int* size) {
    if (n == NULL) {
        return;
    }
    if (n->left != NULL) {
        visitInorder(n->left, acc, size);
    }
    acc[*size] = n->key;
    (*size)++;
    if (n->right != NULL) {
        visitInorder(n->right, acc, size);
    }
}

void print(tree t) {
    int acc[100];
    int size = 0;
    visitInorder(t.root, acc, &size);
    for (int i = 0; i < size; i++) {
        printf(" %d", acc[i]);
    }
    printf("\n");
    
    size = 0;
    visitPreorder(t.root, acc, &size);
    for (int i = 0; i < size; i++) {
        printf(" %d", acc[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    tree t;
    t.root = NULL;
    for (int i = 0; i < n; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(&t, key);
        } else if (strcmp(command, "print") == 0) {
            print(t);
        } else {
            printf("unknown command: %s\n", command);
            exit(1);
        }
    }

    return 0;
}

// 
