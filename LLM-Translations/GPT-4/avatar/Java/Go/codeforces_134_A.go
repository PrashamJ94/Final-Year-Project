package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, sum, c int
	fmt.Scan(&n)
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		sum += arr[i]
	}

	var sb strings.Builder
	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(fmt.Sprintf("%d ", i+1))
		}
	}

	fmt.Println(c)
	fmt.Println(sb.String())
}

// //End of Code
