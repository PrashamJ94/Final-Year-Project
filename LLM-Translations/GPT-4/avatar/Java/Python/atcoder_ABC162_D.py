import sys
from collections import Counter

def main():
    n = int(input().strip())
    s = input().strip()
    counter = Counter(s)
    rc, gc, bc = counter['R'], counter['G'], counter['B']
    result = rc * gc * bc

    for i in range(1, n + 1):
        for k in range(i + 1, n + 1):
            if (i + k) % 2 == 0:
                is_ = s[i - 1]
                ks = s[k - 1]
                js = s[((i + k) // 2) - 1]
                if is_ != ks and ks != js and js != is_:
                    result -= 1

    print(result)

if __name__ == '__main__':
    main()


