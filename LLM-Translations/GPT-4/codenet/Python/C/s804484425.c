
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *pa = (int*)a;
    int *pb = (int*)b;
    return pb[1] - pa[1];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int info[n][2];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &info[i][0], &info[i][1]);
    }

    qsort(info, n, sizeof(info[0]), cmp);

    int selected[k][2], selected_only[n][2], selected_chohuku[n][2], unselected_only[n][2];
    int cnt_selected = 0, cnt_selected_only = 0, cnt_selected_chohuku = 0, cnt_unselected_only = 0;
    int memo[n+1];
    for(int i = 0; i <= n; i++) memo[i] = 0;

    for(int i = 0; i < k; i++) {
        selected[i][0] = info[i][0];
        selected[i][1] = info[i][1];
        if(memo[info[i][0]] == 0) {
            memo[info[i][0]] = 1;
            selected_only[cnt_selected_only][0] = info[i][0];
            selected_only[cnt_selected_only][1] = info[i][1];
            cnt_selected_only++;
        } else {
            selected_chohuku[cnt_selected_chohuku][0] = info[i][0];
            selected_chohuku[cnt_selected_chohuku][1] = info[i][1];
            cnt_selected_chohuku++;
        }
    }

    int cnt_type = cnt_selected_only;
    for(int i = k; i < n; i++) {
        if(memo[info[i][0]] == 0) {
            memo[info[i][0]] = 1;
            unselected_only[cnt_unselected_only][0] = info[i][0];
            unselected_only[cnt_unselected_only][1] = info[i][1];
            cnt_unselected_only++;
        }
    }

    int sum_select = 0;
    for(int i = 0; i < cnt_selected_chohuku; i++) {
        sum_select += selected_chohuku[i][1];
    }
    for(int i = 0; i < cnt_selected_only; i++) {
        sum_select += selected_only[i][1];
    }

    int ans = cnt_type * cnt_type + sum_select;

    for(int i = 0; i < cnt_unselected_only / 2; i++) {
        int temp = unselected_only[cnt_unselected_only - 1][1];
        unselected_only[cnt_unselected_only - 1][1] = unselected_only[i][1];
        unselected_only[i][1] = temp;
    }

    for(int i = 0; i < cnt_selected_chohuku && i < cnt_unselected_only; i++) {
        cnt_type++;
        sum_select += unselected_only[cnt_unselected_only - 1][1];
        sum_select -= selected_chohuku[cnt_selected_chohuku - 1][1];
        cnt_unselected_only--;
        cnt_selected_chohuku--;

        int tmp = cnt_type * cnt_type + sum_select;
        if(tmp > ans) ans = tmp;
    }

    printf("%d\n", ans);

    return 0;
}
