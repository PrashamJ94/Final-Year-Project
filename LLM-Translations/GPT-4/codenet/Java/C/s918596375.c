#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char *s);

int gcd(int a, int b);
long gcd_l(long a, long b);
int lcm(int a, int b);

int main() {
    char s[2];
    scanf("%s", s);

    solve(s);

    return 0;
}

void solve(char *s) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int is_vowel = 0;

    for (int i = 0; i < 5; i++) {
        if (vowels[i] == s[0]) {
            is_vowel = 1;
            break;
        }
    }

    if (is_vowel) {
        printf("vowel\n");
    } else {
        printf("consonant\n");
    }
}

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

long gcd_l(long a, long b) {
    if (a < b) return gcd_l(b, a);
    if (b == 0) return a;
    return gcd_l(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

//
