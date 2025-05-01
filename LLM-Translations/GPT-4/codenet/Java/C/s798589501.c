#include <stdio.h>

int main() {
    int E, Y;
    
    scanf("%d", &E);
    scanf("%d", &Y);

    if (E == 0){
        if (Y <= 1911){
            printf("M");
            printf("%d", Y - 1867);
        }else if(Y <= 1925){
            printf("T");
            printf("%d", Y - 1911);
        }else if(Y <= 1988){
            printf("S");
            printf("%d", Y - 1925);
        }else{
            printf("H");
            printf("%d", Y - 1988);
        }
    } else if(E == 1){
        printf("%d", 1867 + Y);
    }else if(E == 2){
        printf("%d", 1911 + Y);
    }else if(E == 3){
        printf("%d", 1925 + Y);
    }else{
        printf("%d", 1988 + Y);
    }

    return 0;
}
/*  */
