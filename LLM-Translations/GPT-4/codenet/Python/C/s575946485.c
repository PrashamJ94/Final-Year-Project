#include <stdio.h>

int main() {
    int a[5];
    int dic[5];

    for(int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 5; i++) {
        if(a[i] % 10 == 0) {
            dic[i] = 0;
        } else {
            dic[i] = a[i] % 10 - 10;
        }
    }

    int min_num = 0;
    for(int i = 1; i < 5; i++) {
        if(dic[i] < dic[min_num]) {
            min_num = i;
        }
    }

    int a_sum = 0;
    for(int i = 0; i < 5; i++) {
        a_sum += a[i];
    }

    int ans = 0;
    for(int i = 0; i < 5; i++) {
        if(i != min_num) {
            ans += abs(dic[i]);
        }
    }

    printf("%d\n", ans + a_sum);

    return 0;
} // 
