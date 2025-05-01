package main

import (
	"fmt"
)

func main() {
	var n, c int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var l1 [3]int
		sum := 0
		for j := 0; j < 3; j++ {
			fmt.Scan(&l1[j])
			sum += l1[j]
		}
		if sum > 1 {
			c++
		}
	}
	fmt.Println(c)
}

// End of Code
