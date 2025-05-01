package main

import (
	"fmt"
)

func main() {
	var N, count, next int
	fmt.Scan(&N)
	count = 0
	next = 10
	for i := 1; i <= N; i++ {
		count++
		if i == next-1 {
			i = next*10 - 1
			next *= 100
		}
	}
	fmt.Println(count)
}

// 
