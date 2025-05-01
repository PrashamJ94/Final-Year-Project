#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct {
    int data[MAX_NODES];
    int size;
} ArrayList;

ArrayList connect[MAX_NODES];
int visited[MAX_NODES];
bool odd[MAX_NODES];
char print[MAX_NODES * 10];

void dfs(int crt, int parent) {
    visited[crt] = 1;
    ArrayList crtConnect = connect[crt];
    for(int i = 0; i < crtConnect.size; i++) {
        int child = crtConnect.data[i];
        if(child == parent || visited[child] == 1)
            continue;
        else if(visited[child] == 2) {
            sprintf(print + strlen(print), "%d %d\n", crt + 1, child + 1);
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if(odd[child]) {
                sprintf(print + strlen(print), "%d %d\n", child + 1, crt + 1);
                odd[child] = !odd[child];
            } else {
                sprintf(print + strlen(print), "%d %d\n", crt + 1, child + 1);
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge, a, b;
    scanf("%d %d", &numNode, &numEdge);
    for (int i = 0; i < numNode; i++) {
        connect[i].size = 0;
    }
    for (int i = 0; i < numEdge; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        connect[a].data[connect[a].size++] = b;
        connect[b].data[connect[b].size++] = a;
    }
    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }
    dfs(0, -1);
    printf("%s", print);
    return 0;
}

/* //End of Code */
