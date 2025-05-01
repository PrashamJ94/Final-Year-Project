package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	x := 1

	N_list := make([]int, N)
	for i := range N_list {
		N_list[i] = x + 1
		x++
	}

	n := make([][]int, 0)
	for _, i := range N_list {
		for _, j := range N_list {
			for _, k := range N_list {
				n = append(n, []int{i, j, k})
			}
		}
	}

	m := len(n)

	fmt.Println(m)
}

// 
