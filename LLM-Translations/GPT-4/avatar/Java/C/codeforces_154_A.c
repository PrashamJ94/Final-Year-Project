#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char arr[1000];
    scanf("%s", arr);
    int N = strlen(arr);
    int K;
    scanf("%d", &K);
    int res = 0;

    for (int k = 0; k < K; k++) {
        char input[3];
        scanf("%s", input);
        int a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) {
                a++;
            } else if (arr[i] == input[1]) {
                b++;
            } else {
                res += (a < b) ? a : b;
                a = b = 0;
            }
        }
        res += (a < b) ? a : b;
    }

    printf("%d\n", res);

    return 0;
}
// //End of Code
