package main

import (
	"fmt"
	"math"
)

func sum(slice []int) int {
	total := 0
	for _, value := range slice {
		total += value
	}
	return total
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)

	for i := range a {
		fmt.Scan(&a[i])
	}
	for i := range b {
		fmt.Scan(&b[i])
	}
	for i := range c {
		fmt.Scan(&c[i])
	}

	x := sum(a)
	y := sum(b)
	z := sum(c)

	fmt.Println(math.Abs(float64(x - y)))
	fmt.Println(math.Abs(float64(y - z)))
}

// End of Code
