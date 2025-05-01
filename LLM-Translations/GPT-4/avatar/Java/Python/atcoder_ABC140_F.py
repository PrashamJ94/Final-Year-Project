import heapq

def main():
    N = int(input())
    size = 1 << N
    S = list(map(int, input().split()))
    spawned = [False] * size
    spawned[size - 1] = True

    S.sort(reverse=True)
    
    active = [S[size - 1]]
    spawned[size - 1] = True

    for i in range(N):
        active.sort(reverse=True)
        activated = []
        next = size - 1

        for slime in active:
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            if next < 0:
                print("No")
                return
            spawned[next] = True
            activated.append(S[next])

        active.extend(activated)

    print("Yes")

if __name__ == "__main__":
    main()


