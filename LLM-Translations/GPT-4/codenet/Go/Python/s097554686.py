def main():
    size = 100001
    n, t = map(int, input().split())
    mem = [0] * size
    for _ in range(n):
        l, r = map(int, input().split())
        mem[l] += 1
        mem[r] -= 1
    ans = mem[0]
    for i in range(1, t + 1):
        mem[i] += mem[i - 1]
        if ans < mem[i]:
            ans = mem[i]
    print(ans)

main()


