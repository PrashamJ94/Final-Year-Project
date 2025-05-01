#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", (x + y - 3 + ((y - x) % 3 > 0) > 0) ? (x + y - 3 + ((y - x) % 3 > 0)) : 0);
    
    int num_inp;
    scanf("%d", &num_inp);
    
    int arr_inp[num_inp];
    for(int i = 0; i < num_inp; i++){
        scanf("%d", &arr_inp[i]);
    }
    
    int sp_inp1, sp_inp2;
    scanf("%d %d", &sp_inp1, &sp_inp2);
    
    char str_inp[100];
    scanf("%s", str_inp);
    
    return 0;
} //End of Code
