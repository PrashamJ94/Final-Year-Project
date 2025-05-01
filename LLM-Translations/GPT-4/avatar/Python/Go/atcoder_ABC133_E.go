package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	sc = bufio.NewScanner(os.Stdin)
	mod = int(1e9) + 7
	graph map[int][]int
	N, K int
)

func nextInt() int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func dfs(fro, to, f int) int {
	caseNum := f
	colorNum := K - 1
	if f != K {
		colorNum = K - 2
	}
	for _, u := range graph[fro] {
		if u == to {
			continue
		}
		pat := dfs(u, fro, colorNum)
		if pat == 0 {
			caseNum = 0
			break
		}
		caseNum = caseNum * pat % mod
		colorNum -= 1
	}
	return caseNum
}

func main() {
	sc.Split(bufio.ScanWords)
	N, K = nextInt(), nextInt()
	graph = make(map[int][]int, N)
	for i := 0; i < N-1; i++ {
		a, b := nextInt()-1, nextInt()-1
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	ans := dfs(0, -1, K)
	fmt.Println(ans)
}
// End of Code

This go code does the same thing as your Python code. It reads the input, then does a Depth-First-Search (DFS) on the graph to calculate the answer. Please note that Go has different ways to handle inputs and outputs compared to Python.
