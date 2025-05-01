package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	p := make([]int, n)
	p_copy := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
		p_copy[i] = p[i]
	}

	sort.Ints(p)

	count := 0
	for i := 0; i < n; i++ {
		if p[i] != p_copy[i] {
			count += 1
		}
	}

	if count == 0 || count == 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
// 
