#include <stdio.h>

int main() {
    int candeleIntere, b, s = 0, restoSciolte = 0;
    scanf("%d %d", &candeleIntere, &b);
    
    while (candeleIntere > 0 || restoSciolte >= b) {
        candeleIntere += restoSciolte / b;
        restoSciolte %= b;
        s += candeleIntere;
        restoSciolte += candeleIntere % b;
        candeleIntere /= b;
    }
    
    printf("%d", s);
    
    return 0;
} // End of Code
