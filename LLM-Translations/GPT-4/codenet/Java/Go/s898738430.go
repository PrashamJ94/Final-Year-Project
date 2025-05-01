package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	ans := 0
	for i := 1; i < n-1; i++ {
		if a[i] != min(a[i-1], min(a[i], a[i+1])) && a[i] != max(a[i-1], max(a[i], a[i+1])) {
			ans++
		}
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
