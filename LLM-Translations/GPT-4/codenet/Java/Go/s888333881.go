
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Graph0n struct {
	dt []Node0n
}

func NewGraph0n(sz int) *Graph0n {
	g := &Graph0n{}
	for i := 0; i < sz; i++ {
		node1 := Node0n{}
		g.dt = append(g.dt, node1)
	}
	return g
}

func (g *Graph0n) add(vn, val int) {
	g.dt[vn].add(val)
}

func (g *Graph0n) add2(vn, val int) {
	g.dt[vn].add(val)
	g.dt[val].add(vn)
}

func (g *Graph0n) get(vn, index int) int {
	return g.dt[vn].get(index)
}

func (g *Graph0n) getAll(vn int) []int {
	return g.dt[vn].getAll()
}

func (g *Graph0n) sizeOf(vn int) int {
	return g.dt[vn].size()
}

func (g *Graph0n) clear() {
	for i := 0; i < len(g.dt); i++ {
		g.dt[i].clear()
	}
}

type Node0n struct {
	next_vs []int
}

func (n *Node0n) add(val int) {
	n.next_vs = append(n.next_vs, val)
}

func (n *Node0n) get(ad int) int {
	return n.next_vs[ad]
}

func (n *Node0n) getAll() []int {
	return n.next_vs
}

func (n *Node0n) size() int {
	return len(n.next_vs)
}

func (n *Node0n) clear() {
	n.next_vs = []int{}
}

type Edge struct {
	from    int
	v2      int
	weight  int64
}

func NewEdge(vn int, w int64) *Edge {
	return &Edge{
		v2:     vn,
		weight: w,
	}
}

func NewEdge2(cm, vn int, w int64) *Edge {
	return &Edge{
		from:   cm,
		v2:     vn,
		weight: w,
	}
}

type Edge2 struct {
	v2     int
	cost1  int64
	cost2  int64
}

func NewEdge2(vn int, w1, w2 int64) *Edge2 {
	return &Edge2{
		v2:    vn,
		cost1: w1,
		cost2: w2,
	}
}

type Vector struct {
	x int
	y int
}

func NewVector(sx, sy int) *Vector {
	return &Vector{
		x: sx,
		y: sy,
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	s := next(sc)

	flaged := make([]bool, n)
	pop1st := int64(0)

	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	surp1 := int64(0)

	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1++
		}
		surp1 %= (pop1st + 1)
	}

	surp9 := int64(0)
	if pop1st > 1 {
		for i := 0; i < n; i++ {
			surp9 *= 2
			if flaged[i] {
				surp9++
			}
			surp9 %= (pop1st - 1)
		}
	}

	for p := 0; p < n; p++ {
		if flaged[p] {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			dw := surp9

			dif := pow10E97(2, n-p-1, pop1st-1)
			dw -= dif
			dw += (pop1st - 1)
			dw %= (pop1st - 1)

			ans := 1
			for dw != 0 {
				count := countFlaged(dw)
				dw %= count
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1

			dif := pow10E97(2, n-p-1, pop1st+1)
			dw += dif
			dw %= (pop1st + 1)

			ans := 1
			for dw != 0 {
				count := countFlaged(dw)
				dw %= count
				ans++
			}
			fmt.Println(ans)
		}
	}
}

const INF = int(1e8)
const INFL = int64(1e17)
const e97 = int64(1e9) + 7

func abs(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

func absL(a int64) int64 {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

func absD(a float64) float64 {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func minL(a, b int64) int64 {
	if a > b {
		return b
	} else {
		return a
	}
}

func minD(a, b float64) float64 {
	if a > b {
		return b
	} else {
		return a
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxL(a, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxD(a, b float64) float64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func hypod(a, b float64) float64 {
	return a*a + b*b
}

func factorial(n int) int64 {
	ans := int64(1)
	for i := int64(n); i > 0; i-- {
		ans *= i
	}
	return ans
}

func facP(n int, p int64) int64 {
	ans := int64(1)
	for i := int64(n); i > 0; i-- {
		ans *= i
		ans %= p
	}
	return ans
}

func lcm(m, n int64) int64 {
	ans := m / gcd(m, n)
	ans *= n
	return ans
}

func gcd(m, n int64) int64 {
	if m < n {
		return gcd(n, m)
	}
	if n == 0 {
		return m
	}
	return gcd(n, m%n)
}

func is_prime(a int64) bool {
	if a == 1 {
		return false
	}
	for i := int64(2); i*i <= a; i++ {
		if
