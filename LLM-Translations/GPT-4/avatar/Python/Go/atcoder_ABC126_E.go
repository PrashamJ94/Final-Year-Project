package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INF int = 1e18 + 7

var (
	N, M int
	edge [][]int
	used []bool
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	N, M = nextInt(sc), nextInt(sc)

	edge = make([][]int, N)
	used = make([]bool, N)

	for i := 0; i < M; i++ {
		X, Y := nextInt(sc)-1, nextInt(sc)-1
		edge[X] = append(edge[X], Y)
		edge[Y] = append(edge[Y], X)
	}

	ans := 0

	for i := 0; i < N; i++ {
		if !used[i] {
			ans++
			queue := []int{i}
			for len(queue) > 0 {
				node := queue[0]
				queue = queue[1:]
				used[node] = true
				for _, nextnode := range edge[node] {
					if !used[nextnode] {
						queue = append(queue, nextnode)
					}
				}
			}
		}
	}

	fmt.Println(ans)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// End of Code.
