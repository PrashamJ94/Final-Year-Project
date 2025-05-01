package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	s := float64(sum(a)) / float64(4*m)
	if float64(a[m-1]) >= s {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func sum(a []int) int {
	total := 0
	for _, v := range a {
		total += v
	}
	return total
}
// 
