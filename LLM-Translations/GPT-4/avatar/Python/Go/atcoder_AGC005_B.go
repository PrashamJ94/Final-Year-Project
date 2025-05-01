package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

var (
	par  []int
	rank []int
	size []int
)

func root(x int) int {
	if par[x] == x {
		return x
	}
	return root(par[x])
}

func same(x, y int) bool {
	return root(x) == root(y)
}

func unite(x, y int) {
	x, y = root(x), root(y)
	if x != y {
		if rank[x] < rank[y] {
			par[x] = y
			size[y] += size[x]
		} else {
			par[y] = x
			size[x] += size[y]
			if rank[x] == rank[y] {
				rank[x]++
			}
		}
	}
}

func main() {
	data, _ := ioutil.ReadFile("0")
	nums := strings.Fields(string(data))
	n, _ := strconv.Atoi(nums[0])
	nums = nums[1:]
	a := make([]int, len(nums))
	for i, num := range nums {
		a[i], _ = strconv.Atoi(num)
	}
	par = make([]int, n)
	rank = make([]int, n)
	size = make([]int, n)
	for i := range par {
		par[i] = i
		rank[i] = 1
		size[i] = 1
	}
	b := make([]int, n)
	for i, t := range a {
		b[t-1] = i
	}
	c := 0
	for _, k := range b {
		l, r := 1, 1
		if k > 0 && a[k-1] > a[k] {
			l += size[root(k-1)]
			unite(k-1, k)
		}
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(k+1)]
			unite(k+1, k)
		}
		c += l * r * a[k]
	}
	fmt.Println(c)
}

// End of Code

