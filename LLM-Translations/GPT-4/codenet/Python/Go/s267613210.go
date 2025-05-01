package main

import (
	"fmt"
	"sort"
)

func main() {
	var K, N int
	fmt.Scan(&K, &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	dist := make([]int, N)
	for i := 0; i < len(A)-1; i++ {
		dist[i] = A[i+1] - A[i]
	}
	dist[N-1] = K + A[0] - A[N-1]
	sort.Ints(dist)
	maxv := dist[len(dist)-1]
	fmt.Println(sum(dist) - maxv)
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

// 
