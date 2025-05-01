
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    int n;

    scanf("%d", &n);

    char s[50] = "";

    if(n == 0){
        printf("0\n");
        return 0;
    }

    int i = 1;
    while(n != 0){
        if(n % 2 == 0){
            strcat(s, "0");
        } else {
            strcat(s, "1");
        }

        n -= abs(n % 2);

        n /= -2;
    }

    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--){
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}

// 
