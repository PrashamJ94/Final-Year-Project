package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	var flag bool
	fmt.Scan(&a, &b)

	for i := 1; i <= 100000; i++ {
		if math.Floor(float64(i)*0.08) == float64(a) && float64(b) == math.Floor(0.1*float64(i)) {
			fmt.Println(i)
			flag = true
			break
		}
	}

	if !flag {
		fmt.Println(-1)
	}
}

// 
