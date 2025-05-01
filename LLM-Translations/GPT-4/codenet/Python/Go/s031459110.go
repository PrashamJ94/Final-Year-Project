package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	var c string

	fmt.Scan(&N)
	fmt.Scan(&c)

	numW := strings.Count(c, "W")
	numR := N - numW

	comp := strings.Repeat("R", numR) + strings.Repeat("W", numW)
	ans := 0
	for i := 0; i < numR; i++ {
		if c[i] != comp[i] {
			ans++
		}
	}

	ans = min(numW, numR, ans)
	fmt.Println(ans)
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	} else if b < c {
		return b
	}
	return c
}

// 
