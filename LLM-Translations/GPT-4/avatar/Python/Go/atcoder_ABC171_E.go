
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	total := 0
	for _, ai := range a {
		total ^= ai
	}

	results := make([]string, N)
	for i, ai := range a {
		results[i] = strconv.Itoa(ai ^ total)
	}

	fmt.Println(strings.Join(results, " "))
}

// End of Code


