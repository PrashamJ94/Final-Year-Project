#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(long newValue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node* node, long newValue) {
    if (newValue < node->value) {
        if (node->left == NULL) {
            node->left = createNode(newValue);
        } else {
            insert(node->left, newValue);
        }
    } else {
        if (node->right == NULL) {
            node->right = createNode(newValue);
        } else {
            insert(node->right, newValue);
        }
    }
}

void printInOrder(Node* node) {
    if (node->left != NULL) {
        printInOrder(node->left);
    }
    printf(" %ld", node->value);
    if (node->right != NULL) {
        printInOrder(node->right);
    }
}

void printPreOrder(Node* node) {
    printf(" %ld", node->value);
    if (node->left != NULL) {
        printPreOrder(node->left);
    }
    if (node->right != NULL) {
        printPreOrder(node->right);
    }
}

int main() {
    int m;
    scanf("%d", &m);

    Node* tree = NULL;
    for (int i = 0; i < m; i++) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            long key;
            scanf("%ld", &key);
            if (tree == NULL) {
                tree = createNode(key);
            } else {
                insert(tree, key);
            }
        } else {
            if (tree != NULL) {
                printInOrder(tree);
                printf("\n");
                printPreOrder(tree);
                printf("\n");
            }
        }
    }

    return 0;
}

//
