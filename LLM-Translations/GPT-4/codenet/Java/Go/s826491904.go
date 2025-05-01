package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	var max, min float64
	fmt.Scan(&max)
	min = max

	for i := 1; i < N; i++ {
		var in float64
		fmt.Scan(&in)
		max = math.Max(max, in)
		min = math.Min(min, in)
	}

	fmt.Println(max - min)
}
// 
