#include <stdio.h>

int main(){
    int a, b, c;
    char answer[3] = "No";

    scanf("%d %d %d", &a, &b, &c);

    if(a + b >= c) {
        answer[0] = 'Y';
        answer[1] = 'e';
        answer[2] = 's';
    }

    printf("%s\n", answer);

    return 0;
}

// 
