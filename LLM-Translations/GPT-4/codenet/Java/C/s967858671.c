#include <stdio.h>

int main() {
    int Num[11];
    for (int i = 0; i < 10; i++){
        scanf("%d", &Num[i]);
    }

    for (int a = 9; a >= 0; a--){
        for (int b = 0; b < a; b++){
            if (Num[b] < Num[b+1]){
                Num[10] = Num[b];
                Num[b] = Num[b+1];
                Num[b+1] = Num[10];
            }
        }
    }

    printf("%d\n", Num[0]);
    printf("%d\n", Num[1]);
    printf("%d\n", Num[2]);

    return 0;
}
// 
