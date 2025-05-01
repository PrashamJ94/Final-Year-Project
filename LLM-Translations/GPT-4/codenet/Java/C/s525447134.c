#include <stdio.h>
#include <string.h>

int main() {
    char s[10];
    scanf("%s", s);
    
    if (strcmp(s, "Sunny") == 0) {
        printf("Cloudy\n");
    } else if (strcmp(s, "Cloudy") == 0) {
        printf("Rainy\n");
    } else {
        printf("Sunny\n");
    }

    return 0;
}
// 
