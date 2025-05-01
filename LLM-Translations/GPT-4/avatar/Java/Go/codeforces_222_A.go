package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k, l, c int
	fmt.Scan(&n, &k, &l, &c)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	sort.Ints(arr)

	l = arr[n-k]
	c = 0
	for i := 0; i < n; i++ {
		if arr[i] < l {
			c++
		}
	}
	fmt.Println(c)
}

// //End of Code
