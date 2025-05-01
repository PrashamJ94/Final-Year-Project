
#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();  // to consume newline character

    char ans[n][m+1];
    char str[m+1];

    for(int i = 0; i < n; i++) {
        fgets(str, m+1, stdin);
        getchar();  // to consume newline character

        for(int j = 0; j < m; j++) {
            if(str[j] == '-')
                ans[i][j] = '-';
            else {
                if((i + j) % 2 == 1)
                    ans[i][j] = 'W';
                else
                    ans[i][j] = 'B';
            }
        }
        ans[i][m] = '\0';  // terminate the string
    }

    for(int i = 0; i < n; i++) {
        puts(ans[i]);
    }

    return 0;
}
// //End of Code

The above C code reads from the standard input, so you should ensure that the input is provided in the correct format. Also, note that unlike Java, C does not support built-in string handling, so we need to manually add the null character at the end of each string in the 2D array.
