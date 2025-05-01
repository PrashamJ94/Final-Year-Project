#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    bool ju[100001] = {false};
    int pe[100001] = {0};
    int wa = 0;
    int ac = 0;

    for (int i = 0; i < b; i++) {
        int n;
        char res[3];
        scanf("%d %s", &n, res);

        if (strcmp(res, "WA") == 0 && !ju[n - 1]) {
            pe[n - 1]++;
        }

        if (strcmp(res, "AC") == 0) {
            ju[n - 1] = true;
        }
    }

    for (int i = 0; i < a; i++) {
        if (ju[i]) {
            ac++;
            wa += pe[i];
        }
    }

    printf("%d %d\n", ac, wa);
    return 0;
}
// 
