#include <iostream>
#include <vector>
#include <cstdio>

#define PutChar(c) ; *p = (char)(c); ++p;

const int MAX_N = 2000001;
const int MAX_Ai = 10001;
const int STR_SIZE = 10000010;

int getNum(char *&p);
void putNum(int n, char *&p);
void CountingSort(const std::vector<int> &A, std::vector<int> &B, int k, int len);

int main() {
    register int i;
    int n;
    std::vector<int> A(MAX_N);
    std::vector<int> B(MAX_N);
    char str[STR_SIZE];
    char *p = str;

    fread(str, 1, STR_SIZE, stdin);

    n = getNum(p);
    for (i = 1; i <= n; ++i) {
        A[i] = getNum(p);
    }

    CountingSort(A, B, MAX_Ai, n);

    p = str;
    --n;
    for (i = 1; i <= n; ++i) {
        putNum(B[i], p);
        PutChar(' ');
    }
    putNum(B[i], p);
    PutChar('\0');

    puts(str);

    return 0;
}

int getNum(char *&p) {
    int n = 0;
    while ((*p >= '0') && (*p <= '9')) {
        n = n * 10 + (int)(*p - '0');
        ++p;
    }
    ++p;
    return n;
}

void putNum(int n, char *&p) {
    int d;
    if (n < 10) {
        PutChar('0' + n);
        return;
    }
    d = n / 10;
    if (d) putNum(d, p);
    PutChar('0' + (n - (d * 10)));
}

void CountingSort(const std::vector<int> &A, std::vector<int> &B, int k, int len) {
    std::vector<int> C(MAX_Ai, 0);
    int i, j;
    for (j = 1; j <= len; ++j) {
        ++C[A[j]];
    }
    for (i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    for (j = len; j > 0; --j) {
        B[C[A[j]]] = A[j];
        --C[A[j]];
    }
}
// 
