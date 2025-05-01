#include <stdio.h>

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);

    int gate_cond[m][2], max_under_th = 0, min_upper_th = 100000;
    for (i = 0; i < m; i++) {
        scanf("%d %d", &gate_cond[i][0], &gate_cond[i][1]);
        if (gate_cond[i][0] > max_under_th) {
            max_under_th = gate_cond[i][0];
        }
        if (gate_cond[i][1] < min_upper_th) {
            min_upper_th = gate_cond[i][1];
        }
    }

    if (min_upper_th - max_under_th >= 0) {
        printf("%d\n", min_upper_th - max_under_th + 1);
    } else {
        printf("0\n");
    }

    return 0;
}
// 
