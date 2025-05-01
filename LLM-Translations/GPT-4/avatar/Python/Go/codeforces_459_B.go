package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, a, b, ac, bc int
	fmt.Scan(&n)
	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l1[i])
	}
	sort.Ints(l1)
	a = l1[n-1]
	b = l1[0]
	if a == b {
		fmt.Println(a - b, n*(n-1)/2)
	} else {
		for _, v := range l1 {
			if v == a {
				ac++
			}
			if v == b {
				bc++
			}
		}
		fmt.Println(a - b, ac*bc)
	}
}

// End of Code
