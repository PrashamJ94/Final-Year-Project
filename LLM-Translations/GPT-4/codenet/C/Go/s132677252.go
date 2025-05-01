
package main

import (
	"fmt"
	"sort"
)

type graphEdge struct {
	vertex int32
	next   int32
}

type graph struct {
	edge         []graphEdge
	start        []int32
	pointer      int32
	vertexNum    int32
	edgeMaxSize  int32
}

func newGraph(vertexNum int) *graph {
	g := &graph{
		edge:         make([]graphEdge, 1),
		start:        make([]int32, vertexNum),
		pointer:      0,
		vertexNum:    int32(vertexNum),
		edgeMaxSize:  1,
	}
	for i := 0; i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

func addEdge(g *graph, from, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize)...)
	}
	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

const mod int32 = 1000000007

func modPow(r, n int32) int32 {
	t := int32(1)
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = int64(t) * int64(s) % int64(mod)
		}
		s = int64(s) * int64(s) % int64(mod)
		n >>= 1
	}
	return t
}

type node struct {
	one  int32
	zero int32
}

func merge(a []node, n int32) node {
	one := int64(0)
	zero := int64(1)
	total := int64(1)
	for i := int32(0); i < n; i++ {
		one = (one*int64(a[i].zero) + zero*int64(a[i].one)) % int64(mod)
		zero = zero * int64(a[i].zero) % int64(mod)
		total = total * (int64(a[i].zero) + int64(a[i].one)) % int64(mod)
	}
	return node{one: int32(one), zero: int32((total + int64(mod) - one) % int64(mod))}
}

type deque struct {
	array []node
	front int
	last  int
	mask  int
}

func newDeque() *deque {
	d := &deque{
		array: make([]node, 2),
		front: 0,
		last:  0,
		mask:  1,
	}
	return d
}

func getSize(d *deque) int {
	return (d.last + (^d.front + 1)) & d.mask
}

func dequeRealloc(d *deque) {
	array := make([]node, 2*(d.mask+1))
	k := 0
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = array
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

func getAt(d *deque, x int) node {
	return d.array[(d.front+x)&d.mask]
}

func assignAt(d *deque, x int, v node) {
	d.array[(d.front+x)&d.mask] = v
}

func pushFront(d *deque, v node) {
	if ((d.last + 1) & d.mask) == d.front {
		dequeRealloc(d)
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

type bySize []*deque

func (a bySize) Len() int           { return len(a) }
func (a bySize) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a bySize) Less(i, j int) bool { return getSize(a[i]) > getSize(a[j]) }

func run() {
	var n int32
	fmt.Scanf("%d", &n)
	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1
	g := newGraph(int(n) + 1)
	for i := int32(1); i <= n; i++ {
		fmt.Scanf("%d", &p[i])
		addEdge(g, p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)
	for i := int(n); i >= 0; i-- {
		v := int32(i)
		if g.start[v] == -1 {
			dp[v] = newDeque()
			pushFront(dp[v], node{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			sort.Sort(bySize(child[:len]))
			for d := 0; d < getSize(child[1]); d++ {
				j := 0
				for ; j < len && d < getSize(child[j]); j++ {
					lst[j] = getAt(child[j], d)
				}
				assignAt(child[0], d, merge(lst[:j], int32(j)))
			}
			for j := 1; j < len; j++ {
				child[j] = nil
			}
		}
		dp[v] = child[0]
		pushFront(dp[v], node{1, 1})
	}
	ans := int64(0)
	for i := 0; i < getSize(dp[0]); i++ {
		ans += int64(modPow(2, n+1-cnt[i])) * int64(getAt(dp[0], i).one) % int64(mod)
	}
	fmt.Printf("%d\n", ans%int64(mod))
}

func main() {
	run()
}



