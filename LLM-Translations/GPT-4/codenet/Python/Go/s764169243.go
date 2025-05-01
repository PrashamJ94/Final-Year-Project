package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type SegmentTree struct {
	size     int
	defaults int
	seg      []int
}

func NewSegmentTree(size int, defaultVal int) *SegmentTree {
	s := 1
	for s < size {
		s *= 2
	}
	return &SegmentTree{
		size:     s,
		defaults: defaultVal,
		seg:      make([]int, 2*s-1),
	}
}

func (st *SegmentTree) segfunc(x, y int) int {
	return max(x, y)
}

func (st *SegmentTree) update(k, x int) {
	k += st.size - 1
	st.seg[k] = x
	for k > 0 {
		k = (k - 1) / 2
		st.seg[k] = st.segfunc(st.seg[2*k+1], st.seg[2*k+2])
	}
}

func (st *SegmentTree) query(p, q int) int {
	if q <= p {
		return st.defaults
	}
	p += st.size - 1
	q += st.size - 2
	ret := st.defaults
	for q-p > 1 {
		if p&1 == 0 {
			ret = st.segfunc(ret, st.seg[p])
		}
		if q&1 == 1 {
			ret = st.segfunc(ret, st.seg[q])
			q -= 1
		}
		p = p / 2
		q = (q - 1) / 2
	}
	ret = st.segfunc(st.segfunc(ret, st.seg[p]), st.seg[q])
	return ret
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	N := nextInt(sc)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = nextInt(sc)
	}
	ans := make([]int, N)
	for i := 0; i < N; i++ {
		ans[i] = i + 1
	}
	leftSeg := NewSegmentTree(N, 0)
	for i, num := range a {
		ans[num-1] *= i + 1 - leftSeg.query(0, num)
		leftSeg.update(num-1, i+1)
	}
	rightSeg := NewSegmentTree(N, 0)
	for i, num := range reverse(a) {
		ans[num-1] *= i + 1 - rightSeg.query(0, num)
		rightSeg.update(num-1, i+1)
	}

	fmt.Println(sum(ans))
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func sum(slice []int) int {
	total := 0
	for _, v := range slice {
		total += v
	}
	return total
}

func reverse(slice []int) []int {
	n := len(slice)
	reversed := make([]int, n)
	for i := 0; i < n; i++ {
		reversed[i] = slice[n-i-1]
	}
	return reversed
}

// 
