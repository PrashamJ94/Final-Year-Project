#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int n, m;
    char **nImg, **mImg;
} Data;

Data newData();
bool exist(Data d);
bool match(Data d, int x, int y);
char** load(int cnt);

int main() {
    Data d = newData();
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

Data newData() {
    int n, m;
    scanf("%d %d", &n, &m);
    char **nImg = load(n);
    char **mImg = load(m);

    Data d = {n: n, m: m, nImg: nImg, mImg: mImg};
    return d;
}

char** load(int cnt) {
    char **ret = (char**)malloc(cnt * sizeof(char*));
    for (int i = 0; i < cnt; i++) {
        ret[i] = (char*)malloc((cnt + 1) * sizeof(char));
        scanf("%s", ret[i]);
    }
    return ret;
}

bool exist(Data d) {
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool match(Data d, int x, int y) {
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                return false;
            }
        }
    }
    return true;
}
// 
