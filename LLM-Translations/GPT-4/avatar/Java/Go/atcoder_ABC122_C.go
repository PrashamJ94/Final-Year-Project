package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, q int
	var s string
	fmt.Scan(&n, &q, &s)

	c := []rune(s)

	rangeArr := make([][]int, q)
	for i := 0; i < q; i++ {
		rangeArr[i] = make([]int, 2)
		fmt.Scan(&rangeArr[i][0], &rangeArr[i][1])
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for i := 0; i < q; i++ {
		left := rangeArr[i][0]
		right := rangeArr[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

// //End of Code
