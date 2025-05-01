#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    int p;
    int size;
} Scanner;

void init_scanner(Scanner *scanner) {
    scanner->buf = (char *)malloc(1000 * sizeof(char));
    scanner->p = 0;
    scanner->size = 0;
}

char *next(Scanner *scanner) {
    if (scanner->p >= scanner->size) {
        if (fgets(scanner->buf, 1000, stdin) == NULL) {
            return NULL;
        }
        scanner->p = 0;
        scanner->size = strlen(scanner->buf);
    }
    while (scanner->buf[scanner->p] == ' ') {
        scanner->p++;
    }
    int start = scanner->p;
    while (scanner->buf[scanner->p] != ' ' && scanner->buf[scanner->p] != '\n' && scanner->buf[scanner->p] != '\0') {
        scanner->p++;
    }
    char *result = (char *)malloc((scanner->p - start + 1) * sizeof(char));
    strncpy(result, scanner->buf + start, scanner->p - start);
    result[scanner->p - start] = '\0';
    scanner->p++;
    return result;
}

int next_int(Scanner *scanner) {
    char *token = next(scanner);
    int result = atoi(token);
    free(token);
    return result;
}

int main() {
    Scanner scanner;
    init_scanner(&scanner);

    int n = next_int(&scanner);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        double tmp = 1 / (double)next_int(&scanner);
        ans += tmp;
    }
    printf("%lf\n", 1 / ans);

    free(scanner.buf);
    return 0;
}
// 
