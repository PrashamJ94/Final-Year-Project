import sys
from queue import PriorityQueue

def main():
    n, k = map(int, input().split())
    s = input().strip()
    cards = [0] * 26
    for c in s:
        cards[ord(c) - ord('A')] += 1
    cards.sort(reverse=True)
    ans = 0
    for i in range(k):
        change = min(cards[0], k - i)
        ans += change * change
        cards[0] -= change
        i += change - 1
        cards.sort(reverse=True)
    print(ans)

if __name__ == "__main__":
    main()


