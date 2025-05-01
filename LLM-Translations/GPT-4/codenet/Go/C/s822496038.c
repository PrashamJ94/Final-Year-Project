
#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int i;
    if (scanf("%d", &i) != 1) {
        perror("Error reading integer");
        exit(1);
    }
    return i;
}

int main() {
    int appleNum = nextInt();
    int pieceNum = nextInt();
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    printf("%d\n", totalPiece / 2);
    return 0;
}


