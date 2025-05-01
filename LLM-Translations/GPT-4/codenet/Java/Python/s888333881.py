import sys
from typing import List

class Main:
    def __init__(self):
        self.INF = 10**8
        self.INFL = 10**17
        self.e97 = (10**9) + 7

    def main(self):
        n = int(input().strip())
        s = input().strip()
        flaged = [False] * n

        pop1st = 0
        for i in range(n):
            if s[i] == '1':
                flaged[i] = True
                pop1st += 1

        surp1 = 0
        for i in range(n):
            surp1 *= 2
            if flaged[i]:
                surp1 += 1
            surp1 %= (pop1st + 1)

        surp9 = 0
        if pop1st > 1:
            for i in range(n):
                surp9 *= 2
                if flaged[i]:
                    surp9 += 1
                surp9 %= (pop1st - 1)

        for p in range(n):
            if flaged[p]:
                if pop1st == 1:
                    print(0)
                    continue
                dw = surp9

                dif = pow(2, n - p - 1, pop1st - 1)
                dw -= dif
                dw += (pop1st - 1)
                dw %= (pop1st - 1)

                ans = 1
                while dw != 0:
                    count = bin(dw).count("1")
                    dw %= count
                    ans += 1
                print(ans)
            else:
                dw = surp1

                dif = pow(2, n - p - 1, pop1st + 1)
                dw += dif
                dw %= (pop1st + 1)

                ans = 1
                while dw != 0:
                    count = bin(dw).count("1")
                    dw %= count
                    ans += 1
                print(ans)

if __name__ == '__main__':
    main_obj = Main()
    main_obj.main()


