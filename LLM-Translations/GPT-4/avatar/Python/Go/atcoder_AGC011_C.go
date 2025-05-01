package main

import (
	"fmt"
)

type Node struct {
	Val, Color int
}

func main() {
	var n, m, ci, cb, cc int
	fmt.Scan(&n, &m)
	vis := make([]int, n+1)
	g := make([][]int, n+1)
	for i := range g {
		g[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	for i := 1; i <= n; i++ {
		if vis[i] == 0 {
			if len(g[i]) == 0 {
				ci++
			} else {
				if dfs(i, g, vis) {
					cb++
				} else {
					cc++
				}
			}
		}
	}
	fmt.Println(ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb)
}

func dfs(x int, g [][]int, vis []int) bool {
	stk := []Node{{x, 1}}
	flag := true
	for len(stk) > 0 {
		u := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if vis[u.Val] != 0 {
			flag = flag && (vis[u.Val] == u.Color)
			continue
		}
		vis[u.Val] = u.Color
		for _, v := range g[u.Val] {
			stk = append(stk, Node{v, 3 - u.Color})
		}
	}
	return flag
}

// End of Code

