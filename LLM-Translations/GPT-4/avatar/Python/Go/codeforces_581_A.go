package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	minVal := math.Min(float64(a), float64(b))
	maxVal := math.Max(float64(a), float64(b))

	fmt.Println(minVal, int((maxVal-minVal)/2))
}

// End of Code
