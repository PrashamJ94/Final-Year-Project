package main

import (
	"fmt"
)

func main() {
	var N, M, Q int
	fmt.Scan(&N, &M, &Q)

	train := make([][]int, N)
	for i := range train {
		train[i] = make([]int, N)
	}

	for i := 0; i < M; i++ {
		var l, r int
		fmt.Scan(&l, &r)
		train[l-1][r-1]++
	}

	accum := make([][]int, N+1)
	accum[0] = make([]int, N+1)

	for i := 0; i < N; i++ {
		temp := make([]int, N+1)
		v := 0
		for j := 0; j < N; j++ {
			v += train[i][j]
			temp[j+1] = accum[i][j+1] + v
		}
		accum[i+1] = temp
	}

	for i := 0; i < Q; i++ {
		var p, q int
		fmt.Scan(&p, &q)
		v := accum[q][q] - accum[p-1][q] - accum[q][p-1] + accum[p-1][p-1]
		fmt.Println(v)
	}
}

// 
