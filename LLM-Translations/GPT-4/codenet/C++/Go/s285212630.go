
package main

import (
	"fmt"
)

const MAX_L = 22

var N int
var G [100000][]P
var U [MAX_L][100000]int
var R [100000]int
var L [100000]int64

type P struct {
	first  int
	second int64
}

func dfs(x, p, r int, l int64) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp.first
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+pp.second)
	}
}

func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for k := 0; k < MAX_L; k++ {
		if (R[a]-R[b])>>k&1 != 0 {
			b = U[k][b]
		}
	}
	if a == b {
		return a
	}
	for k := MAX_L - 1; k >= 0; k-- {
		if U[k][a] != U[k][b] {
			a = U[k][a]
			b = U[k][b]
		}
	}
	return U[0][a]
}

func dist(x, y int) int64 {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

func main() {
	fmt.Scan(&N)
	for i := 0; i < N-1; i++ {
		var a, b int
		var c int64
		fmt.Scan(&a, &b, &c)
		a--
		b--
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
	}

	for i := 0; i < MAX_L; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}
	dfs(0, -1, 0, 0)
	for i := 0; i < MAX_L-1; i++ {
		for v := 0; v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
			}
		}
	}

	var Q, K int
	fmt.Scan(&Q, &K)
	K--
	for i := 0; i < Q; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		fmt.Println(dist(x, K) + dist(K, y))
	}
}



