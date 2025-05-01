package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	temp := make([]float64, 0)
	for _, x := range arr {
		if x-float64(int(x)) != 0 {
			temp = append(temp, x-float64(int(x)))
		}
	}
	sort.Float64s(temp)
	o := 2*n - len(temp)
	arr_sum := 0.0
	for _, x := range temp {
		arr_sum += x
	}
	res := 2e9
	for i := 0; i <= n; i++ {
		if i+o >= n {
			res = int(math.Min(float64(res), math.Abs(float64(i)-arr_sum)))
		}
	}
	fmt.Printf("%.3f\n", float64(res))
}

// End of Code
