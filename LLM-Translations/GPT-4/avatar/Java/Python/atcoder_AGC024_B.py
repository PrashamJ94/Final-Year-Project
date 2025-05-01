
from collections import defaultdict

def main():
    N = int(input())
    P = list(map(int, input().split()))

    for i in range(N):
        P[i] -= 1

    map_dict = defaultdict(int)
    for i in range(N):
        map_dict[P[i]] = i

    nglist = []
    for i in range(N-1):
        if map_dict[i] > map_dict[i+1]:
            nglist.append(i)

    if not nglist:
        print(0)
        return

    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i+1] - 1, ans)

    print(ans)

if __name__ == "__main__":
    main()


