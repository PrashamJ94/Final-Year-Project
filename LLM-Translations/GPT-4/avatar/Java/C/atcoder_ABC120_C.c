
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *array;
    int top;
    int size;
} Stack;

void Stack_Init(Stack *s, int size) {
    s->array = (char *)malloc(sizeof(char) * size);
    s->top = -1;
    s->size = size;
}

int Stack_IsEmpty(Stack *s) {
    return s->top == -1;
}

void Stack_Push(Stack *s, char value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->array[++s->top] = value;
}

char Stack_Pop(Stack *s) {
    if (Stack_IsEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->array[s->top--];
}

char Stack_Peek(Stack *s) {
    if (Stack_IsEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->array[s->top];
}

int main() {
    char x[1000];
    scanf("%s", x);
    Stack s;
    Stack_Init(&s, strlen(x));
    int c = 0;

    for (int i = 0; i < strlen(x); i++) {
        Stack_Push(&s, x[i]);
        while (s.top > 0) {
            char p = Stack_Pop(&s);
            char q = Stack_Pop(&s);
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            } else {
                Stack_Push(&s, q);
                Stack_Push(&s, p);
                break;
            }
        }
    }

    printf("%d\n", c * 2);
    free(s.array);

    return 0;
}

// //End of Code
