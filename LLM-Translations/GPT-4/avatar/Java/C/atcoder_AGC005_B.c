#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    int leftl[N], rightl[N];
    int que[N], que_front = 0, que_back = 0;
    int index = 0;
    
    while (index < N) {
        while (que_front < que_back && a[que[que_front]] > a[index]) {
            int ind = que[que_front++];
            rightl[ind] = index - ind - 1;
        }
        que[que_back++] = index++;
    }
    
    while (que_front < que_back) {
        int ind = que[que_front++];
        rightl[ind] = N - ind - 1;
    }
    
    index = N - 1;
    que_front = que_back = 0;
    
    while (index >= 0) {
        while (que_front < que_back && a[que[que_front]] > a[index]) {
            int ind = que[que_front++];
            leftl[ind] = ind - index - 1;
        }
        que[que_back++] = index--;
    }
    
    while (que_front < que_back) {
        int ind = que[que_front++];
        leftl[ind] = ind - index - 1;
    }
    
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long long)a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }
    
    printf("%lld\n", ans);
    return 0;
}

// //End of Code
