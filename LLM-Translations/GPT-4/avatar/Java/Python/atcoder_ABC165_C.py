
from itertools import combinations_with_replacement

n, m, q = map(int, input().split())
abcd = [tuple(map(int, input().split())) for _ in range(q)]

def score(seq):
    total = 0
    for a, b, c, d in abcd:
        if seq[b - 1] - seq[a - 1] == c:
            total += d
    return total

ans = -100
for seq in combinations_with_replacement(range(1, m + 1), n):
    ans = max(ans, score(seq))

print(ans)

##End of Code
