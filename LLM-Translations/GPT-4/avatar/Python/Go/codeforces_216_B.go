package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInts() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	data, _ := reader.ReadString('\n')
	fields := strings.Fields(data)
	ints := make([]int, len(fields))
	for i, f := range fields {
		ints[i], _ = strconv.Atoi(f)
	}
	return ints, nil
}

func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
	if seen[i] {
		return 0, 0
	}
	seen[i] = true
	nodes := 1
	edges := len(g[i])
	for j := range g[i] {
		x, y := dfs(g, seen, j)
		nodes += x
		edges += y
	}
	return nodes, edges
}

func solve() bool {
	line0, _ := readInts()
	if len(line0) == 0 {
		return false
	}
	n, m := line0[0], line0[1]
	g := make(map[int]map[int]bool)
	seen := make(map[int]bool)
	for i := 1; i <= n; i++ {
		g[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		a, _ := readInts()
		b, _ := readInts()
		g[a[0]][b[0]] = true
		g[b[0]][a[0]] = true
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if !seen[i] {
			nodes, edges := dfs(g, seen, i)
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++
			}
		}
	}
	if (n-ans)%2 == 1 {
		ans++
	}
	fmt.Println(ans)
	return true
}

func main() {
	for solve() {
	}
}

// End of Code
