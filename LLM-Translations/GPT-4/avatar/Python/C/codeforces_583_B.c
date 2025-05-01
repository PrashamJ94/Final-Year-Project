#include <stdio.h>

void main() {
    int n, i, counter = 0, counter_turns = -1;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while(counter < n) {
        counter_turns++;
        for(i = 0; i < n; i++) {
            if(a[i] != -1 && a[i] <= counter) {
                counter++;
                a[i] = -1;
            }
        }

        // reverse the array
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int temp = a[start];   
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }
    printf("%d", counter_turns);
}

// End of Code
