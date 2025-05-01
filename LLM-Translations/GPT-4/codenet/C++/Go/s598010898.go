
package main

import (
	"fmt"
)

func main() {
	var n, sum int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
		if a[i]-b[i] > 0 {
			sum += a[i] - b[i]
		}
	}
	fmt.Println(sum)
}

// 

