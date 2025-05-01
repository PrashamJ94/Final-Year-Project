#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100], t[100];
    scanf("%s", s);
    int len = strlen(s);
    t[0] = s[0];
    sprintf(t + 1, "%d", len - 2);
    t[strlen(t)] = s[len - 1];
    t[strlen(t)] = '\0';
    printf("%s\n", t);
    return 0;
}
// 
