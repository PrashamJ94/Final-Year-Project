package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	array := make([]int, n)
	max := math.MinInt32
	min := math.MaxInt32

	for i := 0; i < len(array); i++ {
		fmt.Scan(&array[i])
		if max < array[i] {
			max = array[i]
		}
		if min > array[i] {
			min = array[i]
		}
	}
	fmt.Println(max - min)
}

// 
