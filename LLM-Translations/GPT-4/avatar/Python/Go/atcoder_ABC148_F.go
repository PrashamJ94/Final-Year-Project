package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var INF = int(1e9)
var reader = bufio.NewReader(os.Stdin)

func readInts() []int {
	text, _ := reader.ReadString('\n')
	fields := strings.Fields(text)
	ints := make([]int, len(fields))
	for i, v := range fields {
		ints[i], _ = strconv.Atoi(v)
	}
	return ints
}

func dfs(node int, graph [][]int, dist []int) {
	for _, v := range graph[node] {
		if dist[v] != -1 {
			continue
		}
		dist[v] = dist[node] + 1
		dfs(v, graph, dist)
	}
}

func main() {
	input := readInts()
	n, ta, ao := input[0], input[1]-1, input[2]-1
	graph := make([][]int, n)
	for i := 0; i < n-1; i++ {
		input := readInts()
		a, b := input[0]-1, input[1]-1
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	taDist := make([]int, n)
	for i := range taDist {
		taDist[i] = -1
	}
	aoDist := make([]int, n)
	for i := range aoDist {
		aoDist[i] = -1
	}
	taDist[ta], aoDist[ao] = 0, 0
	dfs(ta, graph, taDist)
	dfs(ao, graph, aoDist)
	res := 0
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] {
			continue
		}
		if aoDist[i] > res {
			res = aoDist[i]
		}
	}
	fmt.Println(res - 1)
}

End of Code
