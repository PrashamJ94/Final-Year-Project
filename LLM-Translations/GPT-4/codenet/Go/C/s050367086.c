#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int root(int i, int *uni) {
    if (i == uni[i]) {
        return i;
    }

    uni[i] = root(uni[i], uni);
    return uni[i];
}

typedef struct {
    char *s;
    int *table;
} MP;

void init(MP *mp, char *s) {
    mp->s = s;
    int n = strlen(s);
    mp->table = (int *)malloc((n + 1) * sizeof(int));
    mp->table[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = mp->table[j];
        }
        j++;
        mp->table[i + 1] = j;
    }
}

int main() {
    char s[100001];
    char t[100001];

    scanf("%s", s);
    scanf("%s", t);

    int ns = strlen(s);
    int nt = strlen(t);
    char ss[100001 * (nt / ns + 1)];

    for (int i = 0; i < nt; i += ns) {
        strncpy(ss + i, s, ns);
    }

    char sss[100001 * (nt / ns + 2)];
    strcpy(sss, ss);
    strcat(sss, ss);

    int ok[100001];
    memset(ok, 0, sizeof(ok));

    int uni[100001];
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    MP mp;
    init(&mp, t);
    int m = 0;
    for (int i = 0; i < ns; i++) {
        int o = 1;
        while (m < nt) {
            if (t[m] != sss[i + m]) {
                o = 0;
                break;
            }
            m++;
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }
        i--;
        m++;
    }

    int ans = 0;
    int counter[100001];
    memset(counter, 0, sizeof(counter));

    for (int i = 0; i < ns; i++) {
        int r = root(i, uni);
        if (!ok[r]) {
            continue;
        }
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    printf("%d\n", ans);

    free(mp.table);

    return 0;
}

// 
