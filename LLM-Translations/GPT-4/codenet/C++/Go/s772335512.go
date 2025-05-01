package main

import (
	"fmt"
)

func dfs(v int, G [][]int, used []bool, grundy []int) {
	used[v] = true
	grundy[v] = 0
	for i := 0; i < len(G[v]); i++ {
		if !used[G[v][i]] {
			dfs(G[v][i], G, used, grundy)
			grundy[v] ^= (grundy[G[v][i]] + 1)
		}
	}
}

func main() {
	var N int
	fmt.Scan(&N)

	G := make([][]int, 100000)
	used := make([]bool, 100000)
	grundy := make([]int, 100000)

	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}

	dfs(0, G, used, grundy)

	if grundy[0] != 0 {
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

// 
