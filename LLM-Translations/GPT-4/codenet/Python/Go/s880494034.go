package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	XS := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XS[i])
	}

	m := 9999999999.0
	for i := 1; i <= 100; i++ {
		c := 0.0
		for _, x := range XS {
			c += math.Pow(float64(x-i), 2)
		}
		if m > c {
			m = c
		}
	}

	fmt.Println(m)
}

// 
