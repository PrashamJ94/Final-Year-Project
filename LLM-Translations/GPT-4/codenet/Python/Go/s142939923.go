package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	// A + B
	x := []int{a + b}
	// A - B
	x = append(x, a-b)
	// A * B
	x = append(x, a*b)

	max := x[0]
	for _, value := range x {
		if value > max {
			max = value
		}
	}

	fmt.Println(max)
}

// 
