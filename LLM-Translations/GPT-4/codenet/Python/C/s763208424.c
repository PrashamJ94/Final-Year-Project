
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Heap;

void heapify_down(Heap* heap, int index);
Heap* create_heap(int capacity);
void push(Heap* heap, int value);
int pop(Heap* heap);
int dis(int x, int y);

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    int *a = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Heap* heap = create_heap(n);
    for (i = 0; i < n; i++) {
        push(heap, -a[i]);
    }

    for (i = 0; i < m; i++) {
        push(heap, -dis(-pop(heap), 1));
    }

    int total = 0;
    while (heap->size > 0) {
        total += pop(heap);
    }

    printf("%d\n", -total);
    
    free(heap->data);
    free(heap);
    free(a);

    return 0;
}

void heapify_down(Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[smallest];
        heap->data[smallest] = temp;
        heapify_down(heap, smallest);
    }
}

Heap* create_heap(int capacity) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->data = (int*) malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void push(Heap* heap, int value) {
    if (heap->size >= heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, heap->capacity * sizeof(int));
    }

    heap->data[heap->size++] = value;
    int index = heap->size - 1;

    while (index > 0 && heap->data[index] < heap->data[(index - 1) / 2]) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[(index - 1) / 2];
        heap->data[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

int pop(Heap* heap) {
    if (heap->size == 0) {
        return 0;
    }

    int top = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapify_down(heap, 0);
    return top;
}

int dis(int x, int y) {
    return x / (int)pow(2, y);
}
