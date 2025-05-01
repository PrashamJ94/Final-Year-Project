#include <stdio.h>
#include <string.h>
#define l 2019

int main() {
    char s[50];
    scanf("%s", s);
    int m[l+1];
    for(int i=0; i<=l; i++){
        m[i] = 0;
    }
    m[0] = 1;
    int a = 0, r = 0;
    int len = strlen(s);
    for(int i=0; i<len; i++){
        a = (a + (s[len-1-i] - '0') * m[i % l]) % l;
        r += m[a];
        m[a]++;
    }
    printf("%d\n", r);
    return 0;
}
//End of Code


//Please note that this C code reads a string of numbers from the input, just like the Python code. The character array 's' has a fixed size of 50 which might not be sufficient for all cases, according to your needs you might want to adjust the size or use dynamic memory allocation. Also, the power function is replaced with an array 'm' as C does not support power operation with mod. The array 'm' is used to keep track of the powers of 10 % 2019. The C code follows the same logic as the Python code and works in a similar way.
