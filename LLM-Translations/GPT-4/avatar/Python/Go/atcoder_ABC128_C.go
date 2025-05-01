package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	li := make([][]int, m)
	p := make([]int, m)
	q := make(map[int]bool)
	r := make(map[int]bool)

	for i := 1; i <= n; i++ {
		r[i] = true
	}

	for i := 0; i < m; i++ {
		var k int
		fmt.Scan(&k)
		li[i] = make([]int, k)
		for j := 0; j < k; j++ {
			fmt.Scan(&li[i][j])
			q[li[i][j]] = true
			delete(r, li[i][j])
		}
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&p[i])
	}

	ans := 0
	for i := 0; i < len(q); i++ {
		for s := range combinations(q, i) {
			ok := true
			for u, w := range li {
				if len(intersect(s, w))%2 != p[u] {
					ok = false
					break
				}
			}
			if ok {
				ans += int(math.Pow(2, float64(len(r))))
			}
		}
	}
	fmt.Println(ans)
}

func combinations(iterable map[int]bool, r int) <-chan map[int]bool {
	c := make(chan map[int]bool)
	go func() {
		defer close(c)
		switch r {
		case 0:
			c <- make(map[int]bool)
		case len(iterable):
			c <- iterable
		default:
			for item := range iterable {
				for combination := range combinations(iterable, r-1) {
					combination[item] = true
					c <- combination
				}
			}
		}
	}()
	return c
}

func intersect(a, b map[int]bool) map[int]bool {
	c := make(map[int]bool)
	for item := range a {
		if b[item] {
			c[item] = true
		}
	}
	return c
}

// End of Code

