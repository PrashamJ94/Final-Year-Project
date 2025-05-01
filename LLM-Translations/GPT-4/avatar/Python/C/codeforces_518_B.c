#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[101], t[101];
    int freqs[52] = {0}, freqt[52] = {0};
    int yay = 0, whoops = 0;

    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            freqs[s[i] - 'A']++;
        } else {
            freqs[s[i] - 'a' + 26]++;
        }
    }
    for (int i = 0; t[i] != '\0'; i++) {
        if (isupper(t[i])) {
            freqt[t[i] - 'A']++;
        } else {
            freqt[t[i] - 'a' + 26]++;
        }
    }

    for (int i = 0; i < 52; i++) {
        int temp = (freqs[i] < freqt[i]) ? freqs[i] : freqt[i];
        yay += temp;
        freqs[i] -= temp;
        freqt[i] -= temp;
    }

    for (int i = 0; i < 26; i++) {
        int temp = (freqs[i] < freqt[i + 26]) ? freqs[i] : freqt[i + 26];
        whoops += temp;
        freqs[i] -= temp;
        freqt[i + 26] -= temp;
    }

    for (int i = 26; i < 52; i++) {
        int temp = (freqs[i] < freqt[i - 26]) ? freqs[i] : freqt[i - 26];
        whoops += temp;
        freqs[i] -= temp;
        freqt[i - 26] -= temp;
    }

    printf("%d %d\n", yay, whoops);
    return 0;
}

// End of Code
