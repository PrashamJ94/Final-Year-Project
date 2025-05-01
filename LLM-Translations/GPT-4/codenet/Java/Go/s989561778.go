package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	var digit int
	var sb string
	for {
		n, _ := fmt.Scan(&a, &b)
		if n == 0 {
			break
		}
		digit = int(math.Log10(float64(a+b))) + 1
		sb += fmt.Sprintf("%d\n", digit)
	}
	fmt.Print(sb)
}

// 
