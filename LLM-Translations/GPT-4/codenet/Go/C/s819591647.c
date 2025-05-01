#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int constMod = 1000000007;

// -----------------------------------------

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

void getIntSlice(int n, int *ns) {
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
}

void getString(char *s) {
    scanf("%s", s);
}

// -----------------------------------------

int numAbs(int x) {
    if (x < 0) {
        return -x;
    }

    return x;
}

int numModPow(int a, int n, int m) {
    int result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        n >>= 1;
    }

    return result;
}

int numGcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return numGcd(b, a % b);
}

int numLcm(int a, int b) {
    return a * b / numGcd(a, b);
}

int numModInv(int a, int p) {
    if (a == 1) {
        return 1;
    }

    return p - numModInv(p % a, p) * (p / a) % p;
}

void solve() {
    int n, m;
    n = getInt();
    m = getInt();
    int a[n];
    getIntSlice(n, a);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (double)(4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// -----------------------------------------

int main() {
    solve();
    return 0;
}
// 
