package main

import (
	"fmt"
	"math"
)

func power(a int64) int {
	res := 0
	for a > 0 {
		res++
		a = a / 10
	}
	return res
}

func mult(a int64) int64 {
	pow := power(a)
	var max int64 = 0
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	return a * (max - a)
}

func main() {
	var l, r int64
	fmt.Scan(&l, &r)

	var res int64 = 0
	maxxes := make([]int64, 10)
	var temp int64 = 0

	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		maxxes[i] = temp/2 * (temp - temp/2)
	}

	res = int64(math.Max(float64(mult(l)), float64(res)))
	res = int64(math.Max(float64(mult(r)), float64(res)))
	temp = 0

	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		if l <= temp/2 && temp/2 <= r {
			res = int64(math.Max(float64(maxxes[i]), float64(res)))
		}
	}

	fmt.Println(res)
}

// //End of Code.
