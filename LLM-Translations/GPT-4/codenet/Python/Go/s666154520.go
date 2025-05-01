package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 1; i < 100000; i++ {
		if i*i > n {
			fmt.Println((i - 1) * (i - 1))
			break
		}
	}
}

// 
