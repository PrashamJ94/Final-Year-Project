package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	min := math.MaxInt32
	countNegatives := 0
	sum := int64(0)
	for _, num := range nums {
		abs := int(math.Abs(float64(num)))
		sum += int64(abs)
		if abs < min {
			min = abs
		}
		if num < 0 {
			countNegatives++
		}
	}

	if countNegatives%2 == 0 {
		fmt.Println(sum)
	} else {
		fmt.Println(sum - int64(min*2))
	}
}

// 
