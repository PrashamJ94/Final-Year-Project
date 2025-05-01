
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int s[m], c[m];
    for (int i = 0; i < m; i++){
        scanf("%d%d", &s[i], &c[i]);
        s[i]--;
    }
    for (int i = 0; i < 1000; i++){
        char st[4];
        sprintf(st, "%d", i);
        if (strlen(st) != n){
            continue;
        }
        bool f = true;
        for (int j = 0; j < m; j++){
            if (st[s[j]] == c[j] + '0'){

            } else {
                f = false;
            }
        }
        if (f){
            printf("%d\n", i);
            return 0;
        }

    }
    printf("-1\n");

}

// 
