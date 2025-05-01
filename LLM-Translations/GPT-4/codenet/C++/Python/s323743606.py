import sys

def main():
    m = {}
    for i in range(0, 5001, 200):
        for j in range(0, 5001, 300):
            for k in range(0, 5001, 500):
                w = i + j + k
                p = (i // 5 * 5 * 380 * 0.8 + i % 5 * 380
                     + j // 4 * 4 * 550 * 0.85 + j % 4 * 550
                     + k // 3 * 3 * 850 * 0.88 + k % 3 * 850)
                if w in m:
                    m[w] = min(m[w], p)
                else:
                    m[w] = p

    for n in sys.stdin:
        n = int(n)
        if n == 0:
            break
        print(m[n])

if __name__ == '__main__':
    main()


