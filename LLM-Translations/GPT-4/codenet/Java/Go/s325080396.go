package main

import (
	"fmt"
	"math"
)

const MAX = 200000

func main() {
	var n int
	R := make([]int, MAX)
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&R[i])
	}
	maxv := R[1] - R[0]
	minv := R[0]
	for i := 1; i < n; i++ {
		maxv = int(math.Max(float64(maxv), float64(R[i]-minv)))
		minv = int(math.Min(float64(minv), float64(R[i])))
	}
	fmt.Println(maxv)
}
// 
