package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	input := make([]int, N)
	for i := range input {
		fmt.Scan(&input[i])
	}

	A := sorted(input, N, M)
	fmt.Println(sum(A))
	// 
}

func sorted(A []int, N int, M int) []int {
	sort.Ints(A)
	for M > 0 {
		A[N-1] /= 2
		M--
		i := -2
		for M > 0 && (-N <= i && A[N+i] >= A[N-1]) {
			A[N+i] /= 2
			M--
			i--
		}
		sort.Ints(A)
	}
	return A
}

func sum(A []int) int {
	total := 0
	for _, v := range A {
		total += v
	}
	return total
}
// 
