#include <stdio.h>

int* revpos(int p[], int q[]) {
    static int newpos[2];
    int vec[2];
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    int tmp = 0;
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    return newpos;
}

int main() {
    int input[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    int position[4][2];
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    int* result;
    result = revpos(position[0], position[1]);
    position[2][0] = result[0];
    position[2][1] = result[1];
    result = revpos(position[1], position[2]);
    position[3][0] = result[0];
    position[3][1] = result[1];
    int output[4];
    output[0] = position[2][0];
    output[1] = position[2][1];
    output[2] = position[3][0];
    output[3] = position[3][1];
    for (int i = 0; i < 4; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    return 0;
}
// //End of Code
