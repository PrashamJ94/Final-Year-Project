
package main

import (
	"fmt"
	"sort"
)

type indexVal struct {
	index int32
	val   int32
}

func cmpIndexVal(a, b *indexVal) int {
	d := a.val - b.val
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	} else {
		return 1
	}
}

type segmentNode struct {
	index int32
	val   int64
}

func funcSegmentNode(c, a, b *segmentNode) {
	if a.val < b.val {
		*c = *a
	} else {
		*c = *b
	}
}

type edge struct {
	a, b int32
	c    int64
}

func cmpEdge(a, b *edge) int {
	d := a.c - b.c
	if d == 0 {
		return 0
	} else if d < 0 {
		return -1
	} else {
		return 1
	}
}

type UnionFind struct {
	parent []int32
	size   int32
}

func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size:   size,
	}
	for i := int32(0); i < size; i++ {
		u.parent[i] = -1
	}
	return u
}

func (u *UnionFind) root(x int32) int32 {
	index := make([]int32, 32)
	length := int32(0)
	for u.parent[x] >= 0 {
		index[length] = x
		length++
		x = u.parent[x]
	}
	for length > 0 {
		length--
		u.parent[index[length]] = x
	}
	return x
}

func (u *UnionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y)
}

func (u *UnionFind) getSize(x int32) int32 {
	return -u.parent[u.root(x)]
}

func (u *UnionFind) unite(x, y int32) {
	x = u.root(x)
	y = u.root(y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

func main() {
	var n, d int32
	fmt.Scanf("%d %d", &n, &d)
	a := make([]int32, n)
	p := make([]*indexVal, n)

	for i := int32(0); i < n; i++ {
		fmt.Scanf("%d", &a[i])
		p[i] = &indexVal{index: i, val: a[i]}
	}

	sort.Slice(p, func(i, j int) bool {
		return cmpIndexVal(p[i], p[j]) < 0
	})

	l := newSegmentTree(&segmentNode{index: n, val: int64(n+2)*1000000000 + 1}, n, funcSegmentNode)
	r := newSegmentTree(&segmentNode{index: n, val: int64(n+2)*1000000000 + 1}, n, funcSegmentNode)

	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			t := &segmentNode{}
			l.find(0, v, t)
			r.push(&edge{a: v, b: t.index, c: int64(p[i].val) + t.val - int64(n-1-v)*int64(d)})
		}
		if v+1 < n {
			t := &segmentNode{}
			r.find(v+1, n, t)
			l.push(&edge{a: v, b: t.index, c: int64(p[i].val) + t.val - int64(v)*int64(d)})
		}
		l.update(v, &segmentNode{index: n, val: int64(n+2)*1000000000 + 1})
		r.update(v, &segmentNode{index: n, val: int64(n+2)*1000000000 + 1})
	}

	sum := int64(0)
	u := newUnionFind(n)

	for u.getSize(0) < n {
		e := &edge{}
		l.pop(e)
		if u.same(e.a, e.b) {
			continue
		}
		u.unite(e.a, e.b)
		sum += e.c
	}

	fmt.Printf("%d\n", sum)
}


