package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, 5)
	min := math.MaxInt64
	for i := 0; i < 5; i++ {
		fmt.Scan(&A[i])
		if A[i] < min {
			min = A[i]
		}
	}

	fmt.Println(int(math.Ceil(float64(N)/float64(min))) + 4)
}

// End of Code
