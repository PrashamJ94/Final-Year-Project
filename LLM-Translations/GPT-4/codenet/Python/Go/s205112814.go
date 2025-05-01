package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	gateCond := make([][]int, m)
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		gateCond[i] = []int{x, y}
	}

	maxUnderTh := math.MinInt32
	minUpperTh := math.MaxInt32
	for _, l := range gateCond {
		if l[0] > maxUnderTh {
			maxUnderTh = l[0]
		}
		if l[1] < minUpperTh {
			minUpperTh = l[1]
		}
	}

	if minUpperTh-maxUnderTh >= 0 {
		fmt.Println(minUpperTh - maxUnderTh + 1)
	} else {
		fmt.Println(0)
	}
}
// 
