import sys

def min(a, b):
    if a >= b:
        return b
    return a

def main():
    D, G = map(int, input().split())
    problems = [tuple(map(int, input().split())) for _ in range(D)]

    ans = 10000
    for bit in range(1 << D):
        score = 0
        solved = 0
        ok = False
        for j in range(D):
            if bit & (1 << j) != 0:
                score += (j + 1) * 100 * problems[j][0] + problems[j][1]
                solved += problems[j][0]
        if score < G:
            j = -1
            for i in range(D - 1, -1, -1):
                if bit & (1 << i) == 0:
                    j = i
                    break
            for k in range(problems[j][0]):
                score += (j + 1) * 100
                solved += 1
                if score >= G:
                    ok = True
                    break
            if not ok:
                score += problems[j][1]
                if score >= G:
                    ok = True
        else:
            ok = True
        if ok:
            ans = min(ans, solved)
    print(ans)

main()


