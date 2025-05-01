
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0, c = 0, i;
    scanf("%d", &n);
    int arr[n];
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    char output[1000] = "";
    for (i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            char buf[10];
            sprintf(buf, "%d ", i + 1);
            strcat(output, buf);
        }
    }
    
    printf("%d\n", c);
    printf("%s\n", output);
    
    return 0;
}

// //End of Code
