package main

import (
	"fmt"
	"math"
)

func max(nums ...int) int {
	m := nums[0]
	for _, v := range nums {
		if v > m {
			m = v
		}
	}
	return m
}

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	fmt.Println(max(a*c, b*d, a*d, b*c))
}

//End of Code
