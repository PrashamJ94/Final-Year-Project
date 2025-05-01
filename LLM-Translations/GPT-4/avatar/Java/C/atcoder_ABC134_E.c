#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int key, int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int key, int value) {
    if (node == NULL) {
        return newNode(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = insert(node->right, key, value);
    } else {
        node->value = value;
    }

    return node;
}

int lowerKey(Node* node, int key) {
    if (node == NULL) {
        return -1;
    }

    if (node->key < key) {
        int rightResult = lowerKey(node->right, key);
        return rightResult != -1 ? rightResult : node->key;
    } else {
        return lowerKey(node->left, key);
    }
}

int get(Node* node, int key) {
    if (node == NULL) {
        return 0;
    }

    if (node->key == key) {
        return node->value;
    } else if (node->key < key) {
        return get(node->right, key);
    } else {
        return get(node->left, key);
    }
}

int getCount(Node* node, int *count) {
    if (node == NULL) {
        return 0;
    }

    getCount(node->left, count);
    *count += node->value;
    getCount(node->right, count);

    return *count;
}

int main() {
    int n, num, key, val, ans;
    Node* root = NULL;
    scanf("%d", &n);

    while (n-- > 0) {
        scanf("%d", &num);
        key = lowerKey(root, num);

        if (key == -1) {
            val = get(root, num);
            root = insert(root, num, ++val);
        } else {
            val = get(root, key);

            if (val == 1) {
                root = insert(root, key, 0);
            } else {
                root = insert(root, key, --val);
            }

            val = get(root, num);
            root = insert(root, num, ++val);
        }
    }

    ans = 0;
    int count = 0;
    ans = getCount(root, &count);

    printf("%d\n", ans);

    return 0;
}

// //End of Code
