#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char arr[1000][1000];
    int count[1000] = {0};

    for (int i = 0; i < n; i++) {
        char s[1000];
        fgets(s, 1000, stdin);
        s[strcspn(s, "\n")] = 0;

        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(arr[j], s) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(arr[i], s);
            count[i] = 1;
        }
    }

    int max_count = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    char out_sort[1000][1000];
    int out_sort_count = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] == max_count) {
            strcpy(out_sort[out_sort_count], arr[i]);
            out_sort_count++;
        }
    }

    for (int i = 0; i < out_sort_count - 1; i++) {
        for (int j = i + 1; j < out_sort_count; j++) {
            if (strcmp(out_sort[i], out_sort[j]) > 0) {
                char temp[1000];
                strcpy(temp, out_sort[i]);
                strcpy(out_sort[i], out_sort[j]);
                strcpy(out_sort[j], temp);
            }
        }
    }

    for (int i = 0; i < out_sort_count; i++) {
        printf("%s\n", out_sort[i]);
    }

    return 0;
}
// 
