#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

int pop(Node** head) {
    if (*head == NULL) return -1;
    int poppedValue = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return poppedValue;
}

bool hasNextInt() {
    int c = getchar();
    if (c >= '0' && c <= '9') {
        ungetc(c, stdin);
        return true;
    } else {
        ungetc(c, stdin);
        return false;
    }
}

int main() {
    Node* list = NULL;
    int a;

    while (hasNextInt()) {
        scanf("%d", &a);
        if (a == 0) {
            printf("%d\n", pop(&list));
        } else {
            list = push(list, a);
        }
    }

    return 0;
}
//
