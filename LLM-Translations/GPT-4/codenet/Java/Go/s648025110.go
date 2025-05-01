package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}

	ans := 0
	out := 0

	for i := 0; i < len(h); i++ {
		if out < h[i] {
			ans += h[i] - out
			out = h[i]
		} else {
			out = h[i]
		}
	}

	fmt.Println(ans)
}
// 
