
package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int64
}

type Graph struct {
	vcnt, ecnt int
	e          []Edge
	id         []int
}

func esort(a, b *Edge) bool {
	if a.s < b.s {
		return true
	}
	if a.s > b.s {
		return false
	}
	if a.g < b.g {
		return true
	}
	return false
}

func readgraph(g *Graph) {
	var n, x, y, c int64
	fmt.Scan(&n)
	for i := int64(0); i < n-1; i++ {
		fmt.Scan(&x, &y, &c)
		g.e[2*i] = Edge{s: x, g: y, c: c}
		g.e[2*i+1] = Edge{s: y, g: x, c: c}
	}
	g.vcnt = int(n)
	g.ecnt = 2*int(n) - 2
	sort.Slice(g.e, func(i, j int) bool { return esort(&g.e[i], &g.e[j]) })

	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < int64(i) {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt
}

func tyokkeidfs(s int64, g *Graph, tyokkeitemp []int) {
	for i := g.id[int(s)]; i < g.id[int(s)+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[int(s)] + int(g.e[i].c)
			tyokkeidfs(g.e[i].g, g, tyokkeitemp)
		}
	}
}

func tyokkei(g *Graph) int {
	tyokkeitemp := make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1
	tyokkeidfs(0, g, tyokkeitemp)

	M := 0
	var Mi int
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		tyokkeitemp[i] = 0
	}
	tyokkeitemp[Mi] = 1
	tyokkeidfs(int64(Mi), g, tyokkeitemp)
	for i := 0; i < g.vcnt; i++ {
		if M < tyokkeitemp[i] {
			M = tyokkeitemp[i]
		}
	}
	return M - 1
}

func main() {
	g := Graph{
		e:  make([]Edge, 200010),
		id: make([]int, 100010),
	}
	readgraph(&g)
	fmt.Println(tyokkei(&g))
}


