def miyukiti(asumisu, mizuhasu):
    isihasu, matukisu = asumisu, mizuhasu
    return -1 if isihasu < matukisu else int(isihasu > matukisu)

def sumipe(hayaminn, tomatu, yukinnko):
    satorina, zaasan = 0, yukinnko - 1
    while satorina <= zaasan:
        yukati = satorina + (zaasan - satorina) // 2
        if tomatu[yukati] == hayaminn:
            return yukati
        elif tomatu[yukati] < hayaminn:
            satorina = yukati + 1
        else:
            zaasan = yukati - 1
    return 114513

def main():
    N = int(input())
    A = list(map(int, input().split()))
    tomatu = sorted(A)
    yukinnko = 1
    for inorinn in range(1, N):
        if tomatu[inorinn] != tomatu[yukinnko - 1]:
            tomatu[yukinnko] = tomatu[inorinn]
            yukinnko += 1
    mikakosi = [0] * 114514
    emirinn = 0
    for inorinn in range(N):
        kugyu = sumipe(A[inorinn], tomatu, yukinnko)
        mikakosi[kugyu] = not mikakosi[kugyu]
    for inorinn in range(yukinnko):
        if mikakosi[inorinn]:
            emirinn += 1
    print(emirinn)

if __name__ == '__main__':
    main()


