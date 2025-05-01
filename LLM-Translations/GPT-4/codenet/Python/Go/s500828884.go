package main

import (
	"fmt"
	"math"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	fmt.Println(min(n*a, b))
}

func min(x, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

// 
