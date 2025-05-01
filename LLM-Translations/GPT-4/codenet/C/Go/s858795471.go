package main

import "fmt"

func search(A []int, n int, key int) int {
	i := 0
	A[n] = key
	for A[i] != key {
		i++
	}
	if i != n {
		return 1
	}
	return 0
}

func main() {
	var n, q, key, sum int

	fmt.Scan(&n)
	A := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&key)
		sum += search(A, n, key)
	}
	fmt.Println(sum)
}

// 
