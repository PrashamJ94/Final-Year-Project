import sys
from io import StringIO

def main():
    input = sys.stdin.buffer.readline
    Sd = input().rstrip().decode('utf-8')
    T = input().rstrip().decode('utf-8')
    count = 0
    ok = False
    first = -1
    end = -1
    for j in range(len(Sd)):
        count = 0
        for i in range(len(Sd) - j):
            c = Sd[i + j]
            if c == '?' or c == T[count]:
                count += 1
                if count == len(T):
                    first = i + j - len(T) + 1
                    end = i + j
                    ok = True
                    break
            else:
                count = 0

    if ok:
        for i in range(len(Sd)):
            if first <= i <= end:
                sys.stdout.write(T[i - first])
            else:
                if Sd[i] == '?':
                    sys.stdout.write('a')
                else:
                    sys.stdout.write(Sd[i])
        sys.stdout.write('\n')
    else:
        sys.stdout.write('UNRESTORABLE\n')

main()


