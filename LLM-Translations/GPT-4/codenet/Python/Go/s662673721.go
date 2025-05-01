package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := int(1e18)

	for i := 1; i <= int(math.Sqrt(float64(n))) + 2; i++ {
		if n % i != 0 {
			continue
		}
		j := n / i
		ans = min(ans, i+j - 2)
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
