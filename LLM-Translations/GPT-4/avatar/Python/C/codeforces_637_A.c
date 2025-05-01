#include<stdio.h>
#include<string.h>

#define MAX 100

struct ele {
    char str[MAX];
    int count;
    int first_index;
};

int search(struct ele arr[], int n, char* str) {
    int i;
    for (i=0; i<n; i++)
        if (strcmp(arr[i].str, str) == 0)
            return i;
    return -1;
}

int main() {
    int n;
    char str[MAX];
    struct ele arr[MAX];
    int k=0;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%s", str);
        int j = search(arr, k, str);
        if (j == -1) {
            strcpy(arr[k].str, str);
            arr[k].count = 1;
            arr[k].first_index = i;
            k++;
        } else {
            arr[j].count++;
        }
    }

    int res_index = 0;
    for (int i=1; i<k; i++) {
        if (arr[i].count > arr[res_index].count)
            res_index = i;
        else if (arr[i].count == arr[res_index].count)
            if (arr[i].first_index < arr[res_index].first_index)
                res_index = i;
    }

    printf("%s\n", arr[res_index].str);
    
    return 0;
} //End of Code.
