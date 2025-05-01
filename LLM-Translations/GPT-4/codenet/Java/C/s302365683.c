#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, val, ans = 0;
    scanf("%d", &n);

    int* count = (int*)calloc(10001, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        count[val]++;
    }

    for (int i = 0; i < 10001; i++) {
        int num = count[i];
        if (num > i)
            ans += num - i;
        else if (num < i)
            ans += num;
    }

    printf("%d\n", ans);
    free(count);
    return 0;
}

// 
