
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[n];
    bool isNegative = false;
    int len = 0;
    
    for(int i = 0; i < n; i++) {
        char s[m+1];
        scanf("%s", s);
        
        char* g = strchr(s, 'G');
        char* s_char = strchr(s, 'S');
        
        if(g != NULL && s_char != NULL) {
            int diff = s_char - g;
            if(diff < 0) {
                isNegative = true;
                break;
            }
            
            bool found = false;
            for(int j = 0; j < len; j++) {
                if(c[j] == diff) {
                    found = true;
                    break;
                }
            }
            
            if(!found) {
                c[len++] = diff;
            }
        }
    }
    
    if(isNegative) {
        printf("-1\n");
    } else {
        printf("%d\n", len);
    }

    return 0;
} // End of Code


//This code translates the Python code you provided into C. It reads the number of inputs `n` and the length of each string `m`, then it iterates over the input strings and finds the distances between 'S' and 'G' in each string, storing them in the `c` array. At the end, it prints out the length of the `c` array as the number of unique distances, unless any distance was negative, in which case it prints `-1`.
