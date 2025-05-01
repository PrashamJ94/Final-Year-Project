import heapq
from sys import stdin

INF = 1 << 60


def main():
    H, W, K = map(int, input().split())
    x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
    x1, y1 = y1, x1
    x2, y2 = y2, x2
    c = [input() for _ in range(H)]

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    def to_id(x, y, dir):
        return 4 * (W * y + x) + dir

    def splat_id(id):
        return id // 4 % W, id // 4 // W, id % 4

    dist = [INF] * (W * H * 4)

    q = []
    for i in range(4):
        heapq.heappush(q, (0, to_id(x1, y1, i)))

    while len(q) > 0:
        now_cost, now_id = heapq.heappop(q)
        x, y, dir = splat_id(now_id)
        if c[y][x] == '@':
            continue
        if dist[now_id] <= now_cost:
            continue
        dist[now_id] = now_cost
        if x == x2 and y == y2:
            break
        for i in range(4):
            n_cost = (now_cost + K - 1) // K * K
            n_id = to_id(x, y, i)
            if dist[n_id] <= n_cost:
                continue
            heapq.heappush(q, (n_cost, n_id))
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx < W and 0 <= ny < H:
            n_cost = now_cost + 1
            n_id = to_id(nx, ny, dir)
            if dist[n_id] <= n_cost:
                continue
            heapq.heappush(q, (n_cost, n_id))

    ans = INF
    for i in range(4):
        id = to_id(x2, y2, i)
        if dist[id] < ans:
            d2 = (dist[id] + K - 1) // K
            if d2 < ans:
                ans = d2
    if ans < INF:
        print(ans)
    else:
        print(-1)


main()


