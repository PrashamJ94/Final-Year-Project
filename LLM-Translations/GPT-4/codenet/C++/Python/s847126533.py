
def check(n, wei, book):
    tmp = wei
    n -= 1
    for i in range(len(book)):
        if tmp < book[i]:
            if n > 0:
                n -= 1
                tmp = wei
                if tmp < book[i]:
                    return False
            else:
                return False
        tmp -= book[i]
    return True

def main():
    while True:
        m, n = map(int, input().split())
        if m == 0:
            break
        book = [int(input()) for _ in range(n)]

        l = 0
        r = 1500000
        ans = 0

        while l < r:
            mid = (l + r) // 2
            if check(m, mid, book):
                ans = mid
                if r == mid:
                    break
                r = mid
            else:
                if l == mid:
                    break
                l = mid

        print(ans)

if __name__ == "__main__":
    main()


