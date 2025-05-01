#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

int main() {
    int q, cnt = 0;
    long long const_val = 0, left_sum = 0, right_sum = 0;
    scanf("%d", &q);
    
    Heap left = initHeap(q, true);
    Heap right = initHeap(q, false);
    
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int a, b;
            scanf("%d %d", &a, &b);
            const_val += b;
            
            if (cnt % 2 == 0) {
                if (isEmpty(right)) {
                    insert(left, a);
                    left_sum += a;
                    cnt++;
                    continue;
                }
                
                int c = pop(right);
                right_sum -= c;
                if (a <= c) {
                    insert(left, a);
                    insert(right, c);
                    left_sum += a;
                    right_sum += c;
                } else {
                    insert(left, c);
                    insert(right, a);
                    left_sum += c;
                    right_sum += a;
                }
            } else {
                int c = pop(left);
                left_sum -= c;
                if (a <= -c) {
                    insert(left, -a);
                    insert(right, -c);
                    left_sum += a;
                    right_sum -= c;
                } else {
                    insert(left, c);
                    insert(right, a);
                    left_sum -= c;
                    right_sum += a;
                }
            }
            cnt++;
        } else {
            int tmp = peek(left);
            printf("%d %lld\n", tmp, const_val - left_sum + right_sum + tmp * (cnt % 2));
        }
    }
    
    destroyHeap(left);
    destroyHeap(right);
    
    return 0;
}
