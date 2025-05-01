
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type BIT struct {
	size int
	tree []int
}

func NewBIT(n int) *BIT {
	return &BIT{
		size: n,
		tree: make([]int, n+1),
	}
}

func (bit *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i -= i & -i
	}
	return ret
}

func (bit *BIT) bitsum(l, r int) int {
	if r == -1 {
		return bit._bitsum(l)
	}
	return bit._bitsum(r) - bit._bitsum(l)
}

func (bit *BIT) bitadd(i, x int) {
	i++
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	m := n * (n + 1) / 4
	sc.Scan()
	a := make([]int, n)
	for i, v := range strings.Split(sc.Text(), " ") {
		a[i], _ = strconv.Atoi(v)
	}
	d := map[int]int{}
	_a := append([]int{0}, a...)
	sort.Ints(_a)
	for i, x := range _a {
		d[x] = i
	}
	for i := range a {
		a[i] = d[a[i]]
	}

	check := func(X int) bool {
		b := make([]int, n+1)
		for i, y := range a {
			b[i+1] = b[i] + (2*int(y >= X) - 1)
		}
		c := b[0]
		for _, x := range b {
			if x < c {
				c = x
			}
		}
		for i, x := range b {
			b[i] = x - c
		}
		bit := NewBIT(n + 2)
		ans := 0
		for _, x := range b {
			ans += bit.bitsum(x+1, -1)
			bit.bitadd(x, 1)
		}
		return ans >= m
	}

	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}
	fmt.Println(_a[t[1]])
}
// End of Code

This Go code does the same thing as the Python one. It reads inputs, creates and manipulates binary indexed trees, and checks a condition to print the required output.
