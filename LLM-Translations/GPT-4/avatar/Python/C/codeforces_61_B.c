#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) return 1;
    return 0;
}

double sumn(int i, int n) {
    return ((double)(n - i) * (double)(i + n)) / 2.0;
}

double sqfun(double a, double b, double c) {
    return ((-b + sqrt(b*b - 4.0*a*c)) / (2.0*a));
}

char* f(char* s) {
    char* r = malloc(strlen(s) + 1);
    int j = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] != '-' && s[i] != ';' && s[i] != '_') {
            r[j] = tolower(s[i]);
            j++;
        }
    }
    r[j] = '\0';
    return r;
}

void solve() {
    char* l[3];
    for(int i = 0; i < 3; i++) {
        l[i] = malloc(100);
        scanf("%s", l[i]);
        char* temp = f(l[i]);
        free(l[i]);
        l[i] = temp;
    }

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        char* input = malloc(100);
        scanf("%s", input);
        char* temp = f(input);
        free(input);
        int found = 0;
        for(int j = 0; j < 3; j++) {
            if(strcmp(temp, l[j]) == 0) {
                found = 1;
                break;
            }
        }
        if(found) printf("ACC\n");
        else printf("WA\n");
        free(temp);
    }

    for(int i = 0; i < 3; i++) {
        free(l[i]);
    }
}

int main() {
    solve();
    return 0;
}

// End of Code
