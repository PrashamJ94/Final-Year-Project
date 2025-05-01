
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}
	max := 0
	for l := 0; l < n-1; l++ {
		count := 0
		for l < n-1 && h[l] >= h[l+1] {
			l++
			count++
		}
		if max < count {
			max = count
		}
	}
	fmt.Println(max)
}

// 
