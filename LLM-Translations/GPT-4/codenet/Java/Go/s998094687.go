package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, 3)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[0], &a[1], &a[2])
		sort.Ints(a)

		if math.Pow(float64(a[2]), 2) == math.Pow(float64(a[0]), 2)+math.Pow(float64(a[1]), 2) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// 
