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
	count := 1
	now := 0
	bef := 0
	for i := 1; i < n; i++ {
		if a[i-1] < a[i] {
			now = 1
		} else if a[i-1] > a[i] {
			now = -1
		} else {
			continue
		}
		if bef == 0 {
			bef = now
		}
		if bef != now {
			count++
			bef = 0
		}
	}
	fmt.Println(count)
}

// 
