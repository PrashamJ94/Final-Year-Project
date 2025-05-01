
#include <stdio.h>

typedef struct {
    long module;
} RemRing;

long sum(RemRing *this, long a, long b) {
    return (a + b + this->module) % this->module;
}

long sub(RemRing *this, long a, long b) {
    return (a - b + this->module) % this->module;
}

long prod(RemRing *this, long a, long b) {
    return (a * b) % this->module;
}

long div(RemRing *this, long a, long b) {
    return (a * inv(this, b)) % this->module;
}

long inv(RemRing *this, long a) {
    long b = this->module;
    long u = 1;
    long v = 0;
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        u -= t * v;
        long z = a;
        a = b;
        b = z;
        z = u;
        u = v;
        v = z;
    }
    u %= this->module;
    if (u < 0) u += this->module;
    return u;
}

int main(int argc, char **argv) {
    char s[2];
    scanf("%s", s);
    printf("%c", s[0] + 1);
    return 0;
}

// //End of Code

Note that the C language does not support classes, so the RemRing class from the Java code is represented as a struct in C. The methods of the RemRing class in Java are represented as functions in C, and they take a pointer to a RemRing struct as their first argument. Also, C does not have automatic garbage collection like Java, so you need to manually manage memory if you dynamically allocate any.
