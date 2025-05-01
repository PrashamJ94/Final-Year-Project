#include <stdio.h>

int main(){
    int w, a, b;
    scanf("%d %d %d", &w, &a, &b);

    int answer = (a > b) ? (a - b - w) : (b - a - w);
    if(answer < 0){
        printf("0\n");
    }else{
        printf("%d\n", answer);
    }

    return 0;
}
// 
