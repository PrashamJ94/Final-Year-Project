#include <stdio.h>

int main() {
    int i, num;

    for(i = 0; i < 5; i++){
        scanf("%d", &num);
        if(num == 0){
            printf("%d\n", i+1);
            break;
        }
    }

    return 0;
}
// 
