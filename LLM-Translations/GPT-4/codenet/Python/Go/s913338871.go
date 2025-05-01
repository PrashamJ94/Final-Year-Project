package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	sort.Ints(a)

	s := make([]int, 0)
	for i := N; i < len(a); i += 2 {
		s = append(s, a[i])
	}

	sum := 0
	for _, v := range s {
		sum += v
	}
	fmt.Println(sum)
}
// 
