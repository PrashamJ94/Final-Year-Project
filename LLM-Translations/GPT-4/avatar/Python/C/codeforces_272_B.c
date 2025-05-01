#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    int y = 1;
    while(n != 1) {
        if(n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(int* sequence, int sequence_length) {
    int *storage[100];
    int FXs[100];
    int FXs_length = 0;
    for(int i = 0; i < sequence_length; i++) {
        int y = f(sequence[i]);
        int found = 0;
        for(int j = 0; j < FXs_length; j++) {
            if(FXs[j] == y) {
                found = 1;
                break;
            }
        }
        if(!found) {
            storage[y] = (int*) malloc(sizeof(int));
            storage[y][0] = sequence[i];
            FXs[FXs_length++] = y;
        } else {
            int storage_length = 0;
            while(storage[y][storage_length]) {
                storage_length++;
            }
            storage[y][storage_length] = sequence[i];
        }
    }
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < FXs_length; i++) {
        int y = FXs[i];
        int storage_length = 0;
        while(storage[y][storage_length]) {
            storage_length++;
        }
        sum1 += storage_length * storage_length;
        sum2 += storage_length;
    }
    return (sum1 - sum2) / 2;
}

int main() {
    int sequence_length;
    scanf("%d", &sequence_length);
    int sequence[sequence_length];
    for(int i = 0; i < sequence_length; i++) {
        scanf("%d", &sequence[i]);
    }
    printf("%d\n", nPairsWithCommonFX(sequence, sequence_length));
    return 0;
}

/* End of Code */
