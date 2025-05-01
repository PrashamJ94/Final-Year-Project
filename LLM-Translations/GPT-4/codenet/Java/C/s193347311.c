#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int intLoop;
    scanf("%d", &intLoop);
    char strTaro[100];
    char strHana[100];
    int intTaro = 0;
    int intHana = 0;

    for(int i = 0; i < intLoop; i++){
        scanf("%s", strTaro);
        scanf("%s", strHana);
        int intJudge = strcmp(strTaro, strHana);
        if(intJudge < 0){
            intHana += 3;
        }else if(intJudge == 0){
            intTaro++;
            intHana++;
        }else if(0 < intJudge){
            intTaro += 3;
        }
    }
    printf("%d %d\n", intTaro, intHana);
    return 0;
}
// 
