#include <stdio.h>
#include <stdlib.h>

void B(void);

int main(void){
    B();
    return 0;
}

void B(void){
    long long int x, sum;
    scanf("%lld", &x);
    int i;
    sum = 100;
    for(i = 0; sum < x; ++i){
        sum += sum / 100;
    }
    printf("%d\n", i);
}
/*  */
