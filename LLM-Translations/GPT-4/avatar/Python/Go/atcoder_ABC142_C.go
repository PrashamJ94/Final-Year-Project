
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

type pair struct {
	key   int
	value int
}

func main() {
	var N int
	fmt.Scan(&N)

	// Read input as string, split it, and convert to integers
	input := make([]int, N)
	var s string
	fmt.Scan(&s)
	split := strings.Split(s, " ")
	for i, v := range split {
		input[i], _ = strconv.Atoi(v)
	}

	// Create pair of (index+1, value) and sort by value
	A := make([]pair, N)
	for i, v := range input {
		A[i] = pair{i + 1, v}
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i].value < A[j].value
	})

	// Print indices of sorted pairs
	for i := 0; i < N-1; i++ {
		fmt.Print(A[i].key, " ")
	}
	fmt.Println(A[N-1].key)
}
// End of Code

This Go code does the same thing as the provided Python code: It reads an array from standard input, creates pairs of (index+1, value), sorts these pairs by value, and then prints the indices of the sorted pairs. It uses the sort.Slice function to sort the pairs, and strconv.Atoi to convert strings to integers.
