#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    int n = getNextInt(fp);

    const char *ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(fp);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    fprintf(wfp, "%s\n", ans);

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}
// 
