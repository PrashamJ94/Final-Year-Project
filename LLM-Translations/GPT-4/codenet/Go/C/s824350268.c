
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define mod 1000000007

int getInt();
char* getString();
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int count, ...);
int max(int count, ...);
bool strSearch(char a[], char b);
void printIntArray(int array[], int size);
int calcMod(int x);
char* reverse(char *s);
bool isPrime(int n);

int main() {
    int N = getInt();
    int sqrtN = (int)sqrt(N);

    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N/i) - 2;
        if (num < min) {
            min = num;
        }
    }

    printf("%d\n", min);

    return 0;
}

int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

char* getString() {
    char *s = (char *) malloc(1000 * sizeof(char));
    scanf("%s", s);
    return s;
}

int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    return pow(p, q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p/2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p-1));
    }
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int temp = va_arg(args, int);
        res = res < temp ? res : temp;
    }
    va_end(args);
    return res;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int temp = va_arg(args, int);
        res = res > temp ? res : temp;
    }
    va_end(args);
    return res;
}

bool strSearch(char a[], char b) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int calcMod(int x) {
    return x % mod;
}

char* reverse(char *s) {
    int length = strlen(s);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    int sqrtN = (int)sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// 
