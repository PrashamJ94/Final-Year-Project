
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	m := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&m[i])
	}

	sort.Ints(m)

	result := n + (x - sum(m)) / m[0]
	fmt.Println(result)
}

func sum(arr []int) int {
	total := 0
	for _, value := range arr {
		total += value
	}
	return total
}
// 


