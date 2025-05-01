#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    char res[1000] = "";
    int o = 0, e = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] == 1)
            ++o;
        else 
            ++e;

    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if ((r - l + 1) % 2 == 1)
            strcat(res, "0\n");
        else {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e)
                strcat(res, "1\n");
            else 
                strcat(res, "0\n");
        }
    }
    printf("%s", res);

    return 0;
}
/* //End of Code */
