package main

import (
	"fmt"
	"math"
)

func main() {
	var m, n, x, y int
	fmt.Scan(&m, &n, &x, &y)

	a := make([]int, m)
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, n)
	for i := 0; i < len(b); i++ {
		fmt.Scan(&b[i])
	}

	x_max := MaxInt(x, a)
	y_min := MinInt(y, b)
	CheckWar(x_max, y_min)
}

func MaxInt(x int, a []int) int {
	bignum := x
	for _, v := range a {
		bignum = int(math.Max(float64(bignum), float64(v)))
	}
	return bignum
}

func MinInt(y int, b []int) int {
	smallnum := y
	for _, v := range b {
		smallnum = int(math.Min(float64(smallnum), float64(v)))
	}
	return smallnum
}

func CheckWar(x_max, y_min int) {
	if x_max >= y_min {
		fmt.Println("War")
	} else {
		fmt.Println("No War")
	}
}

// 
