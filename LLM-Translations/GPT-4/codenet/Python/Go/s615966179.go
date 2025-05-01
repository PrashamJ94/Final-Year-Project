package main

import (
	"fmt"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	ans := n / (a + b) * a
	r := min(n%(a+b), a)
	ans += r
	fmt.Println(ans)
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
// 
