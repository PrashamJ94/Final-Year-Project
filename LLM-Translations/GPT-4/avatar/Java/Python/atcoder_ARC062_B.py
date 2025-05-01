Here is the translated Python code:


def solve():
    S = input()
    score = 0
    for i in range(len(S)):
        my = 'g' if i % 2 == 0 else 'p'
        his = S[i]
        if my != his:
            score += 1 if my == 'p' else -1
    print(score)

solve()

##End of Code
