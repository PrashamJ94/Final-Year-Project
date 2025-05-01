#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char txt[100];
    int cu = 0, cl = 0;
    
    printf("Enter a string: ");
    fgets(txt, sizeof(txt), stdin);
    
    for(int i = 0; txt[i]; i++) {
        if(islower(txt[i]))
            cl++;
        else if(isupper(txt[i]))
            cu++;
    }
    
    if(cu > cl) {
        for(int i = 0; txt[i]; i++) {
            txt[i] = toupper(txt[i]);
        }
    } else {
        for(int i = 0; txt[i]; i++) {
            txt[i] = tolower(txt[i]);
        }
    }
    
    printf("%s", txt);
    return 0;
} // End of Code

