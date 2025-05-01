#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int gcd(int a, int b){
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    char S[MAX], T[MAX];
    scanf("%s", S);
    scanf("%s", T);

    int Number_i[N], Number_iMN[N], Number_j[M], Kaburi_j[M], Kaburi_i[M];
    int counter = 0, Flag = 0, Kaburi_Size;

    for(int i=0; i<N; i++){
        Number_i[i] = i;
        Number_iMN[i] = i * M / N;
    }

    for(int j=0; j<M; j++){
        Number_j[j] = j;
    }

    int size = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(Number_iMN[i] == Number_j[j]){
                Kaburi_j[size] = j;
                size++;
            }
        }
    }

    Kaburi_Size = size;

    for(int j=0; j<Kaburi_Size; j++){
        Kaburi_i[j] = Kaburi_j[j] * N / M;
    }

    while(counter <= Kaburi_Size - 1){
        if(S[Kaburi_i[counter]] == T[Kaburi_j[counter]]){
            // do nothing
        }else{
            Flag = 1;
            break;
        }
        counter++;
    }

    if(Flag == 1){
        printf("-1\n");
    }else{
        printf("%d\n", N * M / gcd(N, M));
    }

    return 0;
}

// End of Code
