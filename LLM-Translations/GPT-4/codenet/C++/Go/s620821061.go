package main

import (
	"fmt"
	"math"
)

const MN int = 520

type BitMatching struct {
	G     [2 * MN][]int
	match [2 * MN]int
	used  [2 * MN]bool
}

func (bm *BitMatching) init() {
	for i := 0; i < 2*MN; i++ {
		bm.G[i] = []int{}
	}
}

func (bm *BitMatching) add(a int, b int) {
	bm.G[a] = append(bm.G[a], b+MN)
	bm.G[b+MN] = append(bm.G[b+MN], a)
}

func (bm *BitMatching) dfs(v int) bool {
	bm.used[v] = true
	for i := 0; i < len(bm.G[v]); i++ {
		u := bm.G[v][i]
		w := bm.match[u]
		if w < 0 || (!bm.used[w] && bm.dfs(w)) {
			bm.match[v] = u
			bm.match[u] = v
			return true
		}
	}
	return false
}

func (bm *BitMatching) exec() int {
	res := 0
	for i := 0; i < 2*MN; i++ {
		bm.match[i] = -1
	}
	for v := 0; v < MN; v++ {
		if bm.match[v] < 0 {
			for i := 0; i < 2*MN; i++ {
				bm.used[i] = false
			}
			if bm.dfs(v) {
				res++
			}
		}
	}
	return res
}

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	for {
		var n, m int
		fmt.Scan(&n, &m)
		if n == 0 {
			break
		}
		bm := &BitMatching{}
		bm.init()
		a := make([]int, n)
		b := make([]int, m)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&b[i])
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if gcd(a[i], b[j]) != 1 {
					bm.add(i, j)
				}
			}
		}
		fmt.Println(bm.exec())
	}
}
// 
