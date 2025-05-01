package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

const MOD int = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	uf := NewUnionFind(n)
	sc.Scan()
	m, _ := strconv.Atoi(sc.Text())

	for i := 0; i < m; i++ {
		sc.Scan()
		xyz := strings.Split(sc.Text(), " ")
		x, _ := strconv.Atoi(xyz[0])
		y, _ := strconv.Atoi(xyz[1])
		x--
		y--
		uf.Unite(x, y)
	}

	cnt := 0
	for i := 0; i < n; i++ {
		if uf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

type UnionFind struct {
	n    int
	par  []int
	rank []int
}

func NewUnionFind(n int) *UnionFind {
	uf := new(UnionFind)
	uf.n = n
	uf.par = make([]int, n)
	uf.rank = make([]int, n)

	for i := 0; i < n; i++ {
		uf.par[i] = i
		uf.rank[i] = 0
	}
	return uf
}

func (uf *UnionFind) Find(x int) int {
	if uf.par[x] == x {
		return x
	} else {
		uf.par[x] = uf.Find(uf.par[x])
		return uf.par[x]
	}
}

func (uf *UnionFind) Unite(x int, y int) {
	x = uf.Find(x)
	y = uf.Find(y)

	if x == y {
		return
	}

	if uf.rank[x] < uf.rank[y] {
		uf.par[x] = y
	} else {
		uf.par[y] = x
		if uf.rank[x] == uf.rank[y] {
			uf.rank[x]++
		}
	}
}

func (uf *UnionFind) Same(x int, y int) bool {
	return uf.Find(x) == uf.Find(y)
}

// //End of Code
