#include <stdio.h>
#include <stdbool.h>

int N, M, D, num = 0;
char room[100][100];

void inputRoom() {
    for (int i = 0; i < N; i++) {
        scanf("%s", room[i]);
    }
}

void setWE() {
    bool canPut;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - D + 1; j++) {
            canPut = true;

            for (int k = 0; k < D; k++) {
                if (room[i][j + k] == '#') {
                    canPut = false;
                    break;
                }
            }

            if (canPut == true) {
                num++;
            }
        }
    }
}

void setNS() {
    bool canPut;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - D + 1; j++) {
            canPut = true;

            for (int k = 0; k < D; k++) {
                if (room[j + k][i] == '#') {
                    canPut = false;
                    break;
                }
            }

            if (canPut == true) {
                num++;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &D);
    inputRoom();

    if (M >= D) {
        setWE();
    }

    if (N >= D) {
        setNS();
    }

    printf("%d\n", num);
    return 0;
}

// 
