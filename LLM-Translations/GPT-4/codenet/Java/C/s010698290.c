#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int i, j;
    int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
    long a, b, sum;

    char str[2];

    scanf("%d %d", &n, &m);

    int penal[n+1];
    bool solved[n+1];
    memset(solved, false, sizeof(solved));

    for(i = 0; i < m; i++) {
        scanf("%d %s", &num, str);
        if(str[0] == 'A'){
            solved[num] = true;
        } else if(solved[num] == false) {
            penal[num]++;
        }
    }

    correct_ans = 0;
    num_penal = 0;
    for(i = 1; i <= n; i++) {
        if(solved[i] == true) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    return 0;
}

//
