package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	sum := a + b
	diff := a - b
	prod := a * b

	maxVal := math.Max(float64(sum), math.Max(float64(diff), float64(prod)))
	fmt.Println(int(maxVal))
}
// 
