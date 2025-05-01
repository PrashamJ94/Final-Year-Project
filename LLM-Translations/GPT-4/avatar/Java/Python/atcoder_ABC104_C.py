import sys
from itertools import product

def main():
    D, G = map(int, input().split())
    pc = [tuple(map(int, input().split())) for _ in range(D)]

    ans = 100000
    for bits in product((True, False), repeat=D):
        score = 0
        solve_num = 0
        for i, (p, c) in enumerate(pc):
            if bits[i]:
                score += 100 * (i + 1) * p + c
                solve_num += p

        if score < G:
            for i, (p, c) in reversed(list(enumerate(pc))):
                if not bits[i]:
                    for j in range(p - 1):
                        score += 100 * (i + 1)
                        solve_num += 1
                        if score >= G:
                            break
                if score >= G:
                    break

        if score >= G:
            ans = min(ans, solve_num)

    print(ans)

if __name__ == '__main__':
    main()


