def main():
    while True:
        an = [0] * 20
        a1 = [0] * 6
        a2 = [0] * 6
        an[0], L = map(int, input().split())
        if not L:
            break

        aj = an[0]
        end = 0
        for k in range(1, 21):
            for i in range(L - 1, -1, -1):
                aj, rem = divmod(aj, 10)
                a1[i] = rem
                a2[i] = rem
            for i in range(1, L):
                for j in range(1, L):
                    if a1[j - 1] < a1[j]:
                        a1[j - 1], a1[j] = a1[j], a1[j - 1]
                    if a2[j - 1] > a2[j]:
                        a2[j - 1], a2[j] = a2[j], a2[j - 1]
            d = 1
            max_val = 0
            min_val = 0
            for i in range(L - 1, -1, -1):
                max_val += (a1[i] % 10) * d
                min_val += (a2[i] % 10) * d
                d *= 10
            diff = max_val - min_val
            for i in range(k):
                if diff == an[i]:
                    print(i, diff, k - i)
                    end = 1
                    break
            if end == 1:
                break
            an[k] = diff
            aj = diff

main()


