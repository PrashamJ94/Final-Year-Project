#include <stdio.h>

int main() {
    int sec, per_num;
    double max_sec;
    int ans_num = 0;
    int i;
    
    scanf("%d", &sec);
    scanf("%d", &per_num);
    scanf("%lf", &max_sec);
    max_sec += 0.5;

    for (i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }

    printf("%d\n", ans_num);

    return 0;
}
/* //End of Code */
