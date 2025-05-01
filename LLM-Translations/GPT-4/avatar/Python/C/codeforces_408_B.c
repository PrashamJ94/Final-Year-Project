#include <stdio.h>
#include <string.h>

int main() {
    int t = 1;
    for(int i = 0; i < t; i++) {
        char bought[1000], made[1000];
        int bought_count[26] = {0}, made_count[26] = {0}, res = 0;
        scanf("%s", bought);
        scanf("%s", made);
        int len_bought = strlen(bought);
        int len_made = strlen(made);
        for(int j = 0; j < len_bought; j++) {
            bought_count[bought[j] - 'a']++;
        }
        for(int k = 0; k < len_made; k++) {
            made_count[made[k] - 'a']++;
        }
        for(int l = 0; l < 26; l++) {
            if(made_count[l] > 0 && bought_count[l] == 0) {
                printf("-1\n");
                return 0;
            }
            if(made_count[l] > 0 && bought_count[l] > 0) {
                res += (bought_count[l] < made_count[l]) ? bought_count[l] : made_count[l];
            }
        }
        printf("%d\n", res);
    }
    return 0;
} // End of Code.
