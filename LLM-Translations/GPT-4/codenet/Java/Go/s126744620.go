package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	x := make([]int, 200010)
	for i := 0; i < len(x); i++ {
		x[i] = 0
	}
	for i := 0; i < n; i++ {
		x[a[i]-1]++
	}
	sort.Slice(x, func(i, j int) bool {
		return x[i] < x[j]
	})
	ans := 0
	for i := 0; i <= len(x)-k-1; i++ {
		ans += x[i]
	}
	fmt.Println(ans)
}

// 
