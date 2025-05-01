#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList {
    long value;
    struct LinkedList *next;
} LinkedList;

bool isEmpty(LinkedList *list) {
    return list == NULL;
}

void addLast(LinkedList **list, long value) {
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(*list)) {
        *list = newNode;
    } else {
        LinkedList *temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

long pollFirst(LinkedList **list) {
    if (isEmpty(*list)) {
        return -1;
    } else {
        long value = (*list)->value;
        LinkedList *temp = *list;
        *list = (*list)->next;
        free(temp);
        return value;
    }
}

long getFirst(LinkedList *list) {
    return isEmpty(list) ? -1 : list->value;
}

long getLast(LinkedList *list) {
    if (isEmpty(list)) {
        return -1;
    } else {
        while (list->next != NULL) {
            list = list->next;
        }
        return list->value;
    }
}

int size(LinkedList *list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long ans[n];
    LinkedList *q = NULL;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        while (!isEmpty(q) && getFirst(q) <= t) {
            pollFirst(&q);
        }
        if (size(q) <= b) {
            ans[i] = (isEmpty(q) ? t : getLast(q)) + d;
            addLast(&q, ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%ld ", ans[i]);
    }

    return 0;
}

// //End of Code
