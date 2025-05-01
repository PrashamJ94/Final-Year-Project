#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 LLONG_MAX
#define INF_BIT60 1LL << 60
#define INF_INT32 INT_MAX
#define INF_BIT30 1 << 30
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long T;

typedef struct ReRootingSolver {
    int NodeCount;
    int **Adjacents;
    int **IndexForAdjacents;
    T *Res;
    T **DP;
    T Identity;
    T (*Operate)(T, T);
    T (*OperateNode)(T, int);
} ReRootingSolver;

T f(T x, T y) { return (x * y) % MOD; }

T g(T v, int p) { return v + 1; }

ReRootingSolver* NewReRootingSolver(int nodeCount, int edges[][2], T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));

    s->NodeCount = nodeCount;
    s->Identity = identity;
    s->Operate = operate;
    s->OperateNode = operateNode;

    s->Adjacents = (int **)calloc(nodeCount, sizeof(int *));
    s->IndexForAdjacents = (int **)calloc(nodeCount, sizeof(int *));
    for (int i = 0; i < nodeCount - 1; i++) {
        int x = edges[i][0], y = edges[i][1];
        s->IndexForAdjacents[x] = (int *)realloc(s->IndexForAdjacents[x], (sizeof(s->Adjacents[y]) / sizeof(int) + 1) * sizeof(int));
        s->IndexForAdjacents[y] = (int *)realloc(s->IndexForAdjacents[y], (sizeof(s->Adjacents[x]) / sizeof(int) + 1) * sizeof(int));
        s->Adjacents[x] = (int *)realloc(s->Adjacents[x], (sizeof(s->Adjacents[x]) / sizeof(int) + 1) * sizeof(int));
        s->Adjacents[y] = (int *)realloc(s->Adjacents[y], (sizeof(s->Adjacents[y]) / sizeof(int) + 1) * sizeof(int));
        s->Adjacents[x][sizeof(s->Adjacents[x]) / sizeof(int)] = y;
        s->Adjacents[y][sizeof(s->Adjacents[y]) / sizeof(int)] = x;
    }

    s->DP = (T **)calloc(nodeCount, sizeof(T *));
    s->Res = (T *)calloc(nodeCount, sizeof(T));

    for (int i = 0; i < nodeCount; i++) {
        s->DP[i] = (T *)calloc(sizeof(s->Adjacents[i]) / sizeof(int), sizeof(T));
    }

    if (s->NodeCount > 1) {
        Initialize(s);
    } else {
        s->Res[0] = s->OperateNode(s->Identity, 0);
    }

    return s;
}

T Query(ReRootingSolver *s, int node) {
    return s->Res[node];
}

void Initialize(ReRootingSolver *s) {
    int *parents = (int *)calloc(s->NodeCount, sizeof(int));
    int *order = (int *)calloc(s->NodeCount, sizeof(int));

    int index = 0;
    int stackSize = 1;
    int *stack = (int *)calloc(stackSize, sizeof(int));
    stack[0] = 0;
    parents[0] = -1;
    while (stackSize > 0) {
        int node = stack[--stackSize];
        order[index++] = node;
        for (int i = 0; i < sizeof(s->Adjacents[node]) / sizeof(int); i++) {
            int adjacent = s->Adjacents[node][i];
            if (adjacent == parents[node]) {
                continue;
            }
            stack = (int *)realloc(stack, ++stackSize * sizeof(int));
            stack[stackSize - 1] = adjacent;
            parents[adjacent] = node;
        }
    }

    for (int i = s->NodeCount - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];

        T accum = s->Identity;
        int parentIndex = -1;
        for (int j = 0; j < sizeof(s->Adjacents[node]) / sizeof(int); j++) {
            if (s->Adjacents[node][j] == parent) {
                parentIndex = j;
                continue;
            }
            accum = s->Operate(accum, s->DP[node][j]);
        }
        s->DP[parent][s->IndexForAdjacents[node][parentIndex]] = s->OperateNode(accum, node);
    }

    for (int i = 0; i < s->NodeCount; i++) {
        int node = order[i];
        T accum = s->Identity;
        T *accumsFromTail = (T *)calloc(sizeof(s->Adjacents[node]) / sizeof(int), sizeof(T));
        accumsFromTail[sizeof(accumsFromTail) / sizeof(T) - 1] = s->Identity;
        for (int j = sizeof(accumsFromTail) / sizeof(T) - 1; j >= 1; j--) {
            accumsFromTail[j - 1] = s->Operate(s->DP[node][j], accumsFromTail[j]);
        }
        for (int j = 0; j < sizeof(accumsFromTail) / sizeof(T); j++) {
            s->DP[s->Adjacents[node][j]][s->IndexForAdjacents[node][j]] = s->OperateNode(s->Operate(accum, accumsFromTail[j]), node);
            accum = s->Operate(accum, s->DP[node][j]);
        }
        s->Res[node] = s->OperateNode(accum, node);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int edges[n - 1][2];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &edges[i][0], &edges[i][1]);
        edges[i][0]--;
        edges[i][1]--;
    }

    ReRootingSolver *s = NewReRootingSolver(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", Query(s, i) - 1);
    }

    return 0;
}

// 
