package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}
	var res float64
	for i := 1; i < n; i++ {
		res += math.Abs(float64(b[i] - b[i-1]))
	}
	fmt.Println(res)
}
//End of Code


This Go code does the same thing as the provided Python code. It creates a list `a` from user input, then creates a list `b` where each element is the index of the corresponding element in `a`. It then calculates the sum of the absolute differences between each pair of adjacent elements in `b`, and prints this sum.
