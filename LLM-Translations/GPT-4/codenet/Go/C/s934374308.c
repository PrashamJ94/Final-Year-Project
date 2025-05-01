
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N, K, R, S, P;
    char T[1000];
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    int dict[3] = {0, 0, 0}; // r: 0, s: 1, p: 2
    char char_;
    bool s[N], r[N], p[N];
    for (int i = 0; i < N; i++) {
        s[i] = r[i] = p[i] = true;
    }
    for (int i = 0; i < strlen(T); i++) {
        char_ = T[i];
        if (i >= K) {
            if (char_ == T[i - K]) {
                switch (char_) {
                    case 's':
                        if (s[i % K]) {
                            s[i % K] = false;
                            continue;
                        } else {
                            s[i % K] = true;
                        }
                        break;
                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = false;
                            continue;
                        } else {
                            r[i % K] = true;
                        }
                        break;
                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = false;
                            continue;
                        } else {
                            p[i % K] = true;
                        }
                        break;
                }
            } else {
                switch (char_) {
                    case 's':
                        s[i % K] = true;
                        break;
                    case 'r':
                        r[i % K] = true;
                        break;
                    case 'p':
                        p[i % K] = true;
                        break;
                }
            }
        }
        switch (char_) {
            case 's':
                dict[1]++;
                break;
            case 'r':
                dict[0]++;
                break;
            case 'p':
                dict[2]++;
                break;
        }
    }

    int res = P * dict[0] + S * dict[2] + R * dict[1];
    printf("%d\n", res);

    return 0;
}

// 

