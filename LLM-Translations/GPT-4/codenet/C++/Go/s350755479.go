
package main

import (
	"fmt"
	"sort"
)

const maxn = 1e5 + 5

type Node struct {
	x, y, id int
}

type Edge struct {
	u, v, val int
}

type ByVal []Edge

func (e ByVal) Len() int           { return len(e) }
func (e ByVal) Swap(i, j int)      { e[i], e[j] = e[j], e[i] }
func (e ByVal) Less(i, j int) bool { return e[i].val < e[j].val }

var (
	node [maxn]Node
	e    [maxn << 1]Edge
	par  [maxn]int
	n    int
)

func cmp1(a, b Node) bool {
	return a.x < b.x
}

func cmp2(a, b Node) bool {
	return a.y < b.y
}

func initPar() {
	for i := 0; i <= n; i++ {
		par[i] = i
	}
}

func findpar(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = findpar(par[x])
	return par[x]
}

func unite(x, y int) {
	x = findpar(x)
	y = findpar(y)
	if x == y {
		return
	}
	par[x] = y
}

func main() {

	fmt.Scan(&n)

	initPar()

	for i := 1; i <= n; i++ {
		fmt.Scan(&node[i].x, &node[i].y)
		node[i].id = i
	}

	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp1(node[i], node[j])
	})

	cnt := 0
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
		cnt++
	}

	sort.Slice(node[1:n+1], func(i, j int) bool {
		return cmp2(node[i], node[j])
	})
	for i := 2; i <= n; i++ {
		e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
		cnt++
	}

	sort.Sort(ByVal(e[:cnt]))

	ans := 0
	for i := 0; i < cnt; i++ {
		u, v, val := e[i].u, e[i].v, e[i].val
		if findpar(u) == findpar(v) {
			continue
		}
		unite(u, v)
		ans += val
	}

	fmt.Println(ans)

}
// 


