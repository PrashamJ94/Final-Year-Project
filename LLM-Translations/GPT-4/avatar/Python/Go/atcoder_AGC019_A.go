package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func min(args ...int) int {
	minVal := args[0]
	for _, v := range args {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

func main() {
	var q, h, s, d, n int
	fmt.Scan(&q, &h, &s, &d)
	fmt.Scan(&n)
	best1L := min(q*4, h*2, s)
	best2L := min(d, best1L*2)
	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

// End of Code

