#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int r;
    int c;
} TSize;

typedef struct {
    int **FMemo;
    int FMemoSize;
    TSize *FChain;
    int fChainSize;
} TMcmSolver;

int Count(const TSize *Left, const TSize *Right) {
    return Left->r * Right->c * Left->c;
}

int Solve(TMcmSolver *solver, int s, int l) {
    assert(s <= l);
    if (s == l)
        return 0;
    if (solver->FMemo[s][l] != 0)
        return solver->FMemo[s][l];
    
    if (s + 1 == l) {
        solver->FMemo[s][l] = Count(&solver->FChain[s], &solver->FChain[l]);
    } else {
        int min = INT_MAX;
        for (int i = s; i < l; ++i) {
            TSize left = {solver->FChain[s].r, solver->FChain[i].c};
            TSize right = {solver->FChain[i + 1].r, solver->FChain[l].c};
            int c = Solve(solver, s, i) + Count(&left, &right) + Solve(solver, i + 1, l);
            if (c < min)
                min = c;
        }
        solver->FMemo[s][l] = min;
    }
    return solver->FMemo[s][l];
}

int Answer(TMcmSolver *solver) {
    return Solve(solver, 0, solver->FMemoSize - 1);
}

void TMcmSolver_init(TMcmSolver *solver, TSize *Chain, int ChainSize) {
    solver->FChain = Chain;
    solver->fChainSize = ChainSize;
    solver->FMemoSize = ChainSize;
    solver->FMemo = (int **)malloc(ChainSize * sizeof(int *));
    for (int i = 0; i < ChainSize; ++i) {
        solver->FMemo[i] = (int *)calloc(ChainSize, sizeof(int));
    }
}

void TMcmSolver_free(TMcmSolver *solver) {
    for (int i = 0; i < solver->FMemoSize; ++i) {
        free(solver->FMemo[i]);
    }
    free(solver->FMemo);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    TSize *Chain = (TSize *)malloc(n * sizeof(TSize));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &Chain[i].r, &Chain[i].c);
    }
    TMcmSolver solver;
    TMcmSolver_init(&solver, Chain, n);
    printf("%d\n", Answer(&solver));
    TMcmSolver_free(&solver);
    free(Chain);
    return 0;
}
// 
