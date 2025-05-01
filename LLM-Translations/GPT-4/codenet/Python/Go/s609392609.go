package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	t := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&t[i])
	}
	var m int
	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		var p, x int
		fmt.Scan(&p, &x)
		s := 0
		for j := 0; j < len(t); j++ {
			if j == p-1 {
				s += x
			} else {
				s += t[j]
			}
		}
		fmt.Println(s)
	}
}

// 
