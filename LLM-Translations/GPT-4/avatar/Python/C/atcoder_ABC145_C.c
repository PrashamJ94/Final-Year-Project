#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int fact(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int l, int r, double *distances, int N, int *x, int *y) {
    if (l == r) {
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            int f = arr[i];
            int t = arr[i + 1];
            double distance = sqrt(pow((x[t] - x[f]), 2) + pow((y[t] - y[f]), 2));
            total_distance += distance;
        }
        distances[(*distances_size)++] = total_distance;
    } else {
        for (int i = l; i <= r; i++) {
            swap((arr + l), (arr + i));
            permute(arr, l + 1, r, distances, distances_size, N, x, y);
            swap((arr + l), (arr + i));
        }
    }
}

void solve(int N, int *x, int *y) {
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    int num_permutations = fact(N);
    double distances[num_permutations];
    int distances_size = 0;
    permute(indices, 0, N - 1, distances, &distances_size, N, x, y);

    double result = 0;
    for (int i = 0; i < num_permutations; i++) {
        result += distances[i];
    }
    result /= num_permutations;
    printf("%lf\n", result);
}

int main() {
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    solve(N, x, y);
    return 0;
}

// End of Code
