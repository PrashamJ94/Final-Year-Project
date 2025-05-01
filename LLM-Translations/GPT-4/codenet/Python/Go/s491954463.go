package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, m)
	b := make([]int, m)

	for i := 0; i < m; i++ {
		var a1, b1 int
		fmt.Scan(&a1, &b1)
		a[i] = a1
		b[i] = b1
	}

	for i := 1; i <= n; i++ {
		fmt.Println(countElements(a, i) + countElements(b, i))
	}
}

func countElements(slice []int, element int) int {
	count := 0
	for _, e := range slice {
		if e == element {
			count++
		}
	}
	return count
}
// 
