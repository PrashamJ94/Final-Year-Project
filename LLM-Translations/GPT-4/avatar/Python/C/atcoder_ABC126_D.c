
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_N 100000

typedef struct Node {
    int val;
    int color;
    int a[MAX_N][2];
    int a_size;
} Node;

Node nodes[MAX_N];
int visited[MAX_N];

void traverse(Node* node, int distance) {
    if(visited[node->val - 1])
        return;
    else
        visited[node->val - 1] = 1;

    for(int i=0; i<node->a_size; i++) {
        Node* adjNode = &nodes[node->a[i][0] - 1];
        int dis = node->a[i][1];
        if((distance + dis) % 2 == 0)
            adjNode->color = nodes[0].color;
        else
            adjNode->color = !nodes[0].color;
        traverse(adjNode, distance + dis);
    }
}

int main() {
    int n, u, v, w;
    scanf("%d", &n);
    memset(nodes, 0, n*sizeof(Node));
    memset(visited, 0, n*sizeof(int));
    for(int i=0; i<n-1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        Node* node1 = &nodes[u - 1];
        Node* node2 = &nodes[v - 1];
        node1->val = u;
        node2->val = v;
        node1->a[node1->a_size][0] = v;
        node1->a[node1->a_size][1] = w;
        node1->a_size += 1;
        node2->a[node2->a_size][0] = u;
        node2->a[node2->a_size][1] = w;
        node2->a_size += 1;
    }
    nodes[0].color = 1;

    traverse(&nodes[0], 0);

    for(int i=0; i<n; i++) {
        Node* node = &nodes[i];
        printf("%d\n", node->color ? 1 : 0);
    }

    return 0;
}

// End of Code
