package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, f, c int
	fmt.Scanf("%d\n", &n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d ", &l[i])
	}
	sort.Ints(l)
	for _, i := range l {
		if i > c {
			c++
		}
	}
	fmt.Println(c + 1)
} // End of Code
