#include <stdio.h>
#include <string.h>

int main() {
    char ip[100];
    char st[100] = "";
    printf("Enter a number: ");
    scanf("%s", ip);

    if (strlen(ip) != 1) {
        if (ip[0] == '9') {
            st[0] = '9';
            memmove(ip, ip+1, strlen(ip));
        }
        for (int i = 0; i < strlen(ip); i++) {
            if ((ip[i] - '0') > 4) {
                int n = 9 - (ip[i] - '0');
                st[i] = n + '0';
            } else {
                st[i] = ip[i];
            }
        }
    } else {
        st[0] = ip[0];
    }
    printf("%s", st);

    return 0;
} // End of Code
