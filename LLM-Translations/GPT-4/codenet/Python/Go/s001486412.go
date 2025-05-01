package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	below := 0.0
	for i := 0; i < n; i++ {
		below += 1 / a[i]
	}
	fmt.Println(1 / below)
}

// 
