
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)
	a := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&a[i])
	}
	ans := 0
	i := sort.SearchInts(a, x)
	if i < len(a) {
		ans = min(i, len(a)-i)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// 


