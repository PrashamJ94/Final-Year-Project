#include <stdio.h>

int main() {
    int numlist[5];
    int k;

    for(int i = 0; i < 5; i++) {
        scanf("%d", &numlist[i]);
    }
    scanf("%d", &k);

    if((numlist[4] - numlist[0]) > k) {
        printf(":(\n");
    } else {
        printf("Yay!\n");
    }

    return 0;
}
// 
