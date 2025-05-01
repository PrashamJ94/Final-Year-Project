#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int N = 3;

bool has_consecutive_chars(const char *input_value, int n) {
    int len = strlen(input_value);
    for (int i = 0; i <= len - n; i++) {
        for (int j = 1; j < n; j++) {
            if (input_value[i] != input_value[i + j]) {
                break;
            }
            if (j == n - 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char input_value[5];
    scanf("%s", input_value);

    if (has_consecutive_chars(input_value, N)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// 
