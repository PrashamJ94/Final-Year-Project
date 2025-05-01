package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, 100)
	var avg float64 = 0
	var s, ans float64

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		avg += float64(a[i])
	}
	avg /= float64(n)
	s = math.Abs(float64(a[0]) - avg)
	ans = 0

	for i := 1; i < n; i++ {
		if s > math.Abs(float64(a[i])-avg) {
			s = math.Abs(float64(a[i]) - avg)
			ans = float64(i)
		}
	}
	fmt.Println(ans)
}

// 
