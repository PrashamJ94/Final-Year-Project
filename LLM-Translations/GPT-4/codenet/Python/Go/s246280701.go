package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	ans := math.Pow(10, 10)
	for i := 0; i <= 100; i++ {
		tmp := make([]float64, n)
		for j := 0; j < n; j++ {
			tmp[j] = math.Pow(float64(i-x[j]), 2)
		}

		sum := 0.0
		for _, v := range tmp {
			sum += v
		}

		if sum < ans {
			ans = sum
		}
	}

	fmt.Println(ans)
}
// 
