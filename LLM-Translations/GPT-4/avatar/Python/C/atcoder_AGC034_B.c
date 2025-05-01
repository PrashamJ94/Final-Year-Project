#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b) {
    int temp;
    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve() {
    char s[1000], t[1000];
    scanf("%s", s);
    int i = 0, j = 0;
    while(i < strlen(s)) {
        if(s[i] == 'A') {
            t[j++] = 'A';
            i++;
        }
        else if(s[i] == 'B') {
            if(i < strlen(s) - 1) {
                if(s[i + 1] == 'C') {
                    t[j++] = 'D';
                    i += 2;
                } else {
                    t[j++] = 'X';
                    i++;
                }
            } else {
                t[j++] = 'X';
                i++;
            }
        } else {
            t[j++] = 'X';
            i++;
        }
    }
    t[j] = '\0';
    int total = 0, numA = 0;
    for(i = 0; i < strlen(t); i++) {
        if(t[i] == 'X') {
            numA = 0;
        } else {
            if(t[i] == 'A') numA++;
            else total += numA;
        }
    }
    printf("%d\n", total);
}

int main() {
    solve();
    return 0;
}

// End of Code
