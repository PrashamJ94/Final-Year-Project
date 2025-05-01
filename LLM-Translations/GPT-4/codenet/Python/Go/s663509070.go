package main

import (
	"fmt"
	"math"
)

func main() {
	var N, D int
	fmt.Scan(&N, &D)
	mat := make([][]int, N)
	for d := 0; d < N; d++ {
		row := make([]int, D)
		for i := 0; i < D; i++ {
			fmt.Scan(&row[i])
		}
		mat[d] = row
	}

	c := 0
	for i := 0; i < len(mat)-1; i++ {
		for j := i + 1; j < len(mat); j++ {
			dist := distance(mat[i], mat[j])
			if int(dist) == int(math.Floor(dist)) {
				c++
			}
		}
	}
	fmt.Println(c)
}

func distance(a, b []int) float64 {
	sum := 0.0
	for i := 0; i < len(a); i++ {
		sum += math.Pow(float64(a[i]-b[i]), 2)
	}
	return math.Sqrt(sum)
}

// 
