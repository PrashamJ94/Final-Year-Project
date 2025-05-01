import sys
from io import StringIO

def main():
    input = sys.stdin.buffer.readline
    N, K = map(int, input().split())
    S = input().strip().decode('utf-8')
    firstTime = True
    step = 1

    while K > 0:
        T = S[::-1]
        revU = (S + T)[::-1]
        sDash = S

        for i in range(N, -1, -step):
            tmp = revU[i:i + N]

            if sDash > tmp:
                sDash = tmp
            else:
                if not firstTime:
                    break

        if firstTime:
            firstTime = False
            if pow(2, K) > N:
                c = sDash[0]
                for i in range(N):
                    sys.stdout.write(c)
                sys.stdout.write('\n')
                sys.exit(0)
        else:
            step += step

        K -= 1
        S = sDash[::-1]

    print(S[::-1])

main()


