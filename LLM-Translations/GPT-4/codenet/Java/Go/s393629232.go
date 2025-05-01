package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	minv, maxv := math.MaxInt32, math.MinInt32
	fmt.Scan(&minv)
	for i := 1; i < n; i++ {
		var ri int
		fmt.Scan(&ri)
		maxv = int(math.Max(float64(maxv), float64(ri-minv)))
		minv = int(math.Min(float64(minv), float64(ri)))
	}
	fmt.Println(maxv)
}

// 
