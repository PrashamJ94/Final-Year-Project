#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char s[6], t[6];
    scanf("%s %s", s, t);

    int s_hour, s_minute, t_hour, t_minute;
    sscanf(s, "%d:%d", &s_hour, &s_minute);
    sscanf(t, "%d:%d", &t_hour, &t_minute);

    int diff_hour = s_hour - t_hour;
    int diff_minute = s_minute - t_minute;
    
    if (diff_minute < 0) {
        diff_minute += 60;
        diff_hour--;
    }

    if (diff_hour < 0) {
        diff_hour += 24;
    }

    printf("%02d:%02d\n", diff_hour, diff_minute);

    return 0;
}

// //End of Code
