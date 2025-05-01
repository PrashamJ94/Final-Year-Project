#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int H, W;
char C[510][510];

bool is_right_min(int *a, bool f, int index, int key) {
    if (f && a[index] >= key) return true;
    else if (!f && a[index] > key) return true;
    else return false;
}

int binary_search_right_min(int *a, bool f, int key) {
    int ng = -1;
    int ok = sizeof(a) / sizeof(a[0]);

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (is_right_min(a, f, mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

bool is_left_max(int *a, bool f, int index, int key) {
    if (f && a[index] <= key) return true;
    else if (!f && a[index] < key) return true;
    else return false;
}

int binary_search_left_max(int *a, bool f, int key) {
    int ng = -1;
    int ok = sizeof(a) / sizeof(a[0]);

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (is_left_max(a, f, mid, key)) ng = mid;
        else ok = mid;
    }
    return ng;
}

void solve() {
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j
