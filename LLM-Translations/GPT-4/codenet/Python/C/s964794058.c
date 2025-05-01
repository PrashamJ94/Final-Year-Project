#include <stdio.h>
#include <stdbool.h>

int main() {
    int memTime, memLate[100], color;
    scanf("%d", &memTime);
    for(int i = 0; i < memTime; i++) {
        scanf("%d", &memLate[i]);
    }
    int colorList[10] = {0};
    int memColor = 0;
    int highLate = 0;
    for(int i = 0; i < memTime; i++) {
        int member = memLate[i];
        if (member / 400 >= 8) {
            highLate++;
        } else {
            color = member / 400;
            bool found = false;
            for(int j = 0; j < 10; j++) {
                if (colorList[j] == color) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                colorList[memColor++] = color;
            }
        }
    }
    int maxColor = memColor + highLate;
    int minColor = memColor;
    if (minColor == 0) {
        minColor = 1;
    }
    printf("%d %d\n", minColor, maxColor);
    return 0;
}
// 
