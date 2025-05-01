#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    while(true){
        int sum = 0;
        char s[1000];
        scanf("%s", s);
        if(strcmp(s, "0") == 0) break;
        for(int i = 0; i < strlen(s); i++){
            char a = s[i];
            sum += a - '0';
        }
        printf("%d\n", sum);
    }
    return 0;
}
// 
