package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i], &r[i])
	}
	sum := 0
	for i := 0; i < n; i++ {
		sum += r[i] - l[i] + 1
	}
	fmt.Println(sum)
}
// 
