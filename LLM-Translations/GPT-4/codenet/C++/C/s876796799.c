#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    long long a[200000];
    int ind_a[200000];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        ind_a[a[i] - 1] = i;
    }

    int used_inds[200000] = {0};
    int used_inds_count = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long left_border;
        long long right_border;
        long long cur_ind = ind_a[i];

        used_inds[used_inds_count++] = cur_ind;
        qsort(used_inds, used_inds_count, sizeof(int), compare);

        int *left_it = (int *)bsearch(&cur_ind, used_inds, used_inds_count, sizeof(int), compare);
        int *right_it = (int *)bsearch(&(cur_ind + 1), used_inds, used_inds_count, sizeof(int), compare);

        if (left_it == used_inds) {
            left_border = -1;
        } else {
            if (left_it == used_inds + used_inds_count || *left_it > cur_ind) {
                left_it--;
            }
            left_border = *left_it;
        }
        if (right_it == used_inds + used_inds_count) {
            right_border = N;
        } else {
            right_border = *right_it;
        }
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);
    }

    printf("%lld\n", ans);
    return 0;
}
// 
