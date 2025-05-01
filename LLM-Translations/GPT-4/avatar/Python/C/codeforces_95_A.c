#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pya, i, j, k, l, wat, index;
    char arre[100][100], oString[100], letter1, letter2;
    int valid[100];
    int setcito[100] = { 0 };
    
    scanf("%d", &pya);
    for(i=0; i<pya; i++){
        scanf("%s", arre[i]);
        for(j=0; arre[i][j]; j++){
            arre[i][j] = tolower(arre[i][j]);
        }
    }
    
    scanf("%s", oString);
    for(i=0; oString[i]; i++){
        oString[i] = tolower(oString[i]);
    }
    
    scanf(" %c", &letter1);
    letter1 = tolower(letter1);
    letter2 = (letter1 != 'a') ? 'a' : 'b';
    
    for(i=0; i<strlen(oString); i++){
        valid[i] = 0;
    }
    
    for(i=0; i<pya; i++){
        wat = 0;
        while(1){
            char *ptr = strstr(oString+wat, arre[i]);
            if(ptr){
                index = ptr - oString;
                for(j=index; j<index+strlen(arre[i]); j++){
                    setcito[j] = 1;
                }
                wat = index + 1;
            } else {
                break;
            }
        }
    }
    
    for(i=0; i<strlen(oString); i++){
        if(setcito[i]){
            oString[i] = (oString[i] == letter1) ? letter2 : letter1;
            oString[i] = islower(oString[i]) ? oString[i] : toupper(oString[i]);
        }
    }
    
    printf("%s\n", oString);
    
    return 0;
}

/* End of Code */
