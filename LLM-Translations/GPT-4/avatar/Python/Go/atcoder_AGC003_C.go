package main

import (
	"fmt"
)

func main() {
	var N, cnt int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		var temp int
		fmt.Scan(&temp)
		A[i] = temp*N + i
	}
	sort.Ints(A)
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}
	fmt.Println(cnt / 2)
}
//End of Code.
