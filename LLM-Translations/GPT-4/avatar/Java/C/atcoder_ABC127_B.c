
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFFER_SIZE 10240

typedef struct {
    FILE *in;
    char buffer[BUFFER_SIZE];
    int pos, limit;
    bool eof;
} SimpleScanner;

void init_SimpleScanner(SimpleScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->pos = scanner->limit = 0;
    scanner->eof = false;
}

char read(SimpleScanner *scanner) {
    if (scanner->pos == scanner->limit) {
        scanner->pos = 0;
        scanner->limit = fread(scanner->buffer, 1, BUFFER_SIZE, scanner->in);
        if (scanner->limit == 0) {
            scanner->eof = true;
            return '\0';
        }
    }
    return scanner->buffer[scanner->pos++];
}

void checkEof(SimpleScanner *scanner) {
    if (scanner->eof) {
        fprintf(stderr, "End of file reached\n");
        exit(EXIT_FAILURE);
    }
}

char nextChar(SimpleScanner *scanner) {
    checkEof(scanner);
    char c = read(scanner);
    checkEof(scanner);
    return c;
}

int nextInt(SimpleScanner *scanner) {
    char c;
    do {
        c = read(scanner);
        checkEof(scanner);
    } while (isspace(c));
    int n = 0, sign = 1;
    if (c == '-') {
        sign = -1;
        c = read(scanner);
    }
    while (isdigit(c)) {
        n = n * 10 + (c - '0');
        c = read(scanner);
    }
    return n * sign;
}

long long nextLong(SimpleScanner *scanner) {
    char c;
    do {
        c = read(scanner);
        checkEof(scanner);
    } while (isspace(c));
    long long n = 0;
    int sign = 1;
    if (c == '-') {
        sign = -1;
        c = read(scanner);
    }
    while (isdigit(c)) {
        n = n * 10 + (c - '0');
        c = read(scanner);
    }
    return n * sign;
}

int main() {
    SimpleScanner scanner;
    init_SimpleScanner(&scanner, stdin);
    int r = nextInt(&scanner);
    int d = nextInt(&scanner);
    long long x = nextLong(&scanner);
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        printf("%lld\n", x);
    }
    return 0;
}

// //End of Code

