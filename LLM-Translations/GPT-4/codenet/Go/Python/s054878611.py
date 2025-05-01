def solution(n: int, a: List[int]) -> int:
    memo = [0] * (int(1e5) + 2)
    for num in a:
        memo[num] += 1
        memo[num + 1] += 1
        memo[num + 2] += 1
    out = 0
    for num in memo:
        if num > 0:
            out = max(out, num)
    return out

def max(x: int, y: int) -> int:
    if x > y:
        return x
    return y

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    print(solution(n, a))


