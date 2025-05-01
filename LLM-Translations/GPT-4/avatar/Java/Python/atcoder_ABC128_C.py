import sys
from itertools import product

def main():
    N, M = map(int, input().split())
    switches = [list(map(int, input().split()))[1:] for _ in range(M)]
    p = list(map(int, input().split()))

    ans = 0
    for state in product([0, 1], repeat=N):
        on_lights = 0
        for i in range(M):
            on_switches = sum(state[s - 1] for s in switches[i])
            if on_switches % 2 == p[i]:
                on_lights += 1
        if on_lights == M:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()


