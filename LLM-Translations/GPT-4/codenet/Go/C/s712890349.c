
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Value;
    int Len;
} Block;

void run_length(const char* s, Block** blocks, int* blocks_count);
int max(int a, int b);

int main() {
    int N, K, ans;
    scanf("%d %d", &N, &K);
    char S[1000001];
    scanf("%s", S);
    Block* blocks;
    int blocks_count;
    run_length(S, &blocks, &blocks_count);
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < blocks_count; r++) {
        sum += blocks[r].Len;
        if (blocks[r].Value == '0') {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == '0') {
                zero--;
            }
            l++;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    free(blocks);
    return 0;
}

void run_length(const char* s, Block** blocks, int* blocks_count) {
    int len = strlen(s);
    if (len == 0) {
        *blocks = NULL;
        *blocks_count = 0;
        return;
    }
    *blocks = (Block*)malloc(sizeof(Block) * len);
    *blocks_count = 0;
    Block t = {s[0], 1};
    for (int i = 1; i < len; i++) {
        if (t.Value == s[i]) {
            t.Len++;
        } else {
            (*blocks)[*blocks_count] = t;
            (*blocks_count)++;
            t.Value = s[i];
            t.Len = 1;
        }
    }
    (*blocks)[*blocks_count] = t;
    (*blocks_count)++;
}

int max(int a, int b) {
    return b > a ? b : a;
}

// 
