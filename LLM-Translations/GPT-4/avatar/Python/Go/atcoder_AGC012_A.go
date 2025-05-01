
package main

import (
	"fmt"
	"sort"
)

func readInts() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := range arr {
		fmt.Scan(&arr[i])
	}
	return arr
}

func main() {
	var n int
	fmt.Scan(&n)
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}

// End of Code
