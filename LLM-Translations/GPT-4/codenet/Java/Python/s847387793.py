def main():
    n, m, q = map(int, input().split())
    queries = [tuple(map(int, input().split())) for _ in range(q)]

    def dfs(array):
        if len(array) > n:
            score = 0
            for a, b, c, d in queries:
                if array[b - 1] - array[a - 1] == c:
                    score += d
            return score

        max_score = 0
        last = array[-1]
        for i in range(last, m + 1):
            new_array = array + [i]
            max_score = max(max_score, dfs(new_array))

        return max_score

    max_score = dfs([1])
    print(max_score)

if __name__ == "__main__":
    main()


