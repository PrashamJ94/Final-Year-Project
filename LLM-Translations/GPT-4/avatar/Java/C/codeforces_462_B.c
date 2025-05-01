#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int left;
} c462b;

int compare(const void *a, const void *b) {
    c462b *card_a = (c462b *)a;
    c462b *card_b = (c462b *)b;
    return card_b->left - card_a->left;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    c462b cards[26];
    for (int i = 0; i < 26; i++) {
        cards[i].left = 0;
    }
    
    char s[n + 1];
    scanf("%s", s);

    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }

    long long ans = 0;
    for (int i = 0; i < k;) {
        qsort(cards, 26, sizeof(c462b), compare);
        int change = cards[25].left < k - i ? cards[25].left : k - i;
        ans += (long long)change * change;
        cards[25].left -= change;
        i += change;
    }

    printf("%lld\n", ans);

    return 0;
}

// //End of Code.
