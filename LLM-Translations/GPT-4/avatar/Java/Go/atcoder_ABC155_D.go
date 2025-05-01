package main

import (
	"fmt"
	"sort"
)

var n int
var k int64
var a []int64

func main() {
	fmt.Scan(&n, &k)
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })

	var INF int64 = 1e18 + 1
	var l, r int64 = -INF, INF
	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64) bool {
	var tot int64 = 0
	for i := 0; i < n; i++ {
		now := a[i]
		var l, r int = 0, n
		if now >= 0 {
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(n - l)
		}
		if a[i]*a[i] < x {
			tot--
		}
	}
	if tot/2 < k {
		return true
	} else {
		return false
	}
}

// //End of Code.
