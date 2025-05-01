Below is the translation of your Java code to C:

C
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int count;
bool seen[1000];
int path = 0, cycle = 1;

struct Node {
   int data;
   struct Node* next;
};

struct LinkedList {
   struct Node* head;
} graph[1000];

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addEdge(int src, int dest) {
    struct Node* node = newNode(dest);
    node->next = graph[src].head;
    graph[src].head = node;
}

int dfs(int child, int par) {
    if(seen[child] == true)
        return cycle;
    seen[child] = true;
    struct Node* node = graph[child].head;
    while(node != NULL) {
        if(node->data != par) {
            count++;
            if(dfs(node->data, child) == cycle)
                return cycle;
        }
        node = node->next;
    }
    return path;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i=0; i<=m; i++) {
        graph[i].head = NULL;
        seen[i] = false;
    }

    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }

    int toremove = 0;
    for(int i=1; i<=m; i++) {
        if(!seen[i]) {
            count = 0;
            if(dfs(i, 0) == cycle) {
                if(count % 2 == 1)
                    toremove++;
            }
        }
    }

    if((m - toremove) % 2 == 1)
        toremove++;

    printf("%d\n", toremove);

    return 0;
}

//End of Code
