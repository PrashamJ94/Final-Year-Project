package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	po := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&po[i])
		m -= po[i]
	}
	sort.Ints(po)
	fmt.Println(n + m/po[0])
}
// 
