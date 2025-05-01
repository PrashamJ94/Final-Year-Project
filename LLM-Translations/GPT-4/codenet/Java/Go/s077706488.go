package main

import (
	"fmt"
)

func main() {
	var N, X int
	fmt.Scan(&N, &X)
	m := make([]int, N)
	fmt.Scan(&m[0])
	X -= m[0]
	min := m[0]
	for i := 1; i < N; i++ {
		fmt.Scan(&m[i])
		X -= m[i]
		if m[i] < min {
			min = m[i]
		}
	}
	fmt.Println(N + X/min)
}
// 
