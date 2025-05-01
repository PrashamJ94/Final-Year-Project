def count_black(h, w, m):
    count = 0
    for i in range(h):
        for j in range(w):
            if m[i][j] == 35:
                count += 1
    return count

def solve(h, w, k, m):
    result = 0
    for i in range(1 << h):
        for k in range(1 << w):
            tmp = [row.copy() for row in m]
            for j in range(h):
                h_painted = (1 << j) & i
                if h_painted > 0:
                    for l in range(w):
                        tmp[j][l] = 1

            for j in range(w):
                w_painted = (1 << j) & k
                if w_painted > 0:
                    for l in range(h):
                        tmp[l][j] = 1

            if count_black(h, w, tmp) == a:
                result += 1
    return result

if __name__ == "__main__":
    h, w, k = map(int, input().split())
    m = [list(map(int, list(input()))) for _ in range(h)]
    answer = solve(h, w, k, m)
    print(answer)


