#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MOD 1000000

long long fac[MAX_SIZE];
long long inv[MAX_SIZE];
long long finv[MAX_SIZE];

typedef struct Pair {
    long long a, b;
} Pair;

typedef struct FastScanner {
    FILE *file;
    char buffer[1024];
    int ptr, len;
} FastScanner;

void initFastScanner(FastScanner *sc, FILE *file) {
    sc->file = file;
    sc->ptr = 0;
    sc->len = 0;
}

bool hasNextByte(FastScanner *sc) {
    if (sc->ptr < sc->len) {
        return true;
    } else {
        sc->ptr = 0;
        sc->len = fread(sc->buffer, 1, sizeof(sc->buffer), sc->file);
        if (sc->len == 0) {
            return false;
        }
    }
    return true;
}

int readByte(FastScanner *sc) {
    if (hasNextByte(sc)) {
        return sc->buffer[sc->ptr++];
    } else {
        return -1;
    }
}

bool isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

bool hasNext(FastScanner *sc) {
    while (hasNextByte(sc) && !isPrintableChar(sc->buffer[sc->ptr])) {
        sc->ptr++;
    }
    return hasNextByte(sc);
}

int nextInt(FastScanner *sc) {
    int x = 0;
    bool minus = false;
    int b = readByte(sc);
    if (b == '-') {
        minus = true;
        b = readByte(sc);
    }
    if (b < '0' || '9' < b) {
        fprintf(stderr, "Invalid character for integer: %c\n", b);
        exit(1);
    }
    while (true) {
        if ('0' <= b && b <= '9') {
            x = x * 10 + b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
            return minus ? -x : x;
        } else {
            fprintf(stderr, "Invalid character for integer: %c\n", b);
            exit(1);
        }
        b = readByte(sc);
    }
}

void solve() {
    FILE *file = stdin;
    FastScanner sc;
    initFastScanner(&sc, file);

    int n = nextInt(&sc);
    int m = nextInt(&sc);
    int map[10] = {0};

    for (int i = 0; i < m; i++) {
        int s = nextInt(&sc);
        int c = nextInt(&sc);
        if (map[s] != 0 && map[s] != c) {
            printf("-1\n");
            return;
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[4];
        snprintf(s, sizeof(s), "%03d", i);
        bool flag = true;
        if (strlen(s) < n) continue;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != 0 && map[j + 1] != s[j] - '0') || (map[j + 1] == 0 && s[j] != '0')) {
                if (map[j + 1] == 0 && j == 0 && s[j] == '1') {
                    continue;
                }
                flag = false;
                break;
            }
        }
        if (flag && strlen(s) == n) {
            printf("%s\n", s);
            return;
        }
    }

    printf("-1\n");
}

int main() {
    solve();
    return 0;
}
