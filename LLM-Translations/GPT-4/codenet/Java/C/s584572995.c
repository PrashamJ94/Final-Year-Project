#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

void init_arraylist(ArrayList *list) {
    list->capacity = 10;
    list->size = 0;
    list->data = (int *)malloc(list->capacity * sizeof(int));
}

void add_arraylist(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int get_arraylist(ArrayList *list, int index) {
    return list->data[index];
}

void free_arraylist(ArrayList *list) {
    free(list->data);
}

int mod_pow(long x, long y) {
    if (y == 0)
        return 1;
    if (y % 2 != 0)
        return x * mod_pow(x, y - 1) % MOD;
    long tmp = mod_pow(x, y / 2);
    return tmp * tmp % MOD;
}

ArrayList *to;
int *dp;

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < to[v].size; i++) {
        int next = get_arraylist(&to[v], i);
        if (next == parent) continue;
        res += rec(next, v);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);
    to = (ArrayList *)malloc(N * sizeof(ArrayList));
    for (int i = 0; i < N; i++)
        init_arraylist(&to[i]);
    int edges[N - 1][2];
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        A--; B--;
        add_arraylist(&to[A], B);
        add_arraylist(&to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }
    dp = (int *)malloc(N * sizeof(int));
    rec(0, -1);
    long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;
        long a = dp[child];
        long b = N - a;
        long mul = (mod_pow(2, a) - 1) * (mod_pow(2, b) - 1) % MOD;
        mulsum += mul;
        mulsum %= MOD;
    }
    long cases = mod_pow(2, N);
    long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long BN = N * mod_pow(2, N - 1) % MOD;
    long WN = (PN - BN + MOD) % MOD;
    long ans = WN * mod_pow(cases, MOD - 2);
    ans %= MOD;
    printf("%ld\n", ans);
    for (int i = 0; i < N; i++)
        free_arraylist(&to[i]);
    free(to);
    free(dp);
    return 0;
}
