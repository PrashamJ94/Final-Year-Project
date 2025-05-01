package main

import (
	"fmt"
)

func main() {
	var w, a, b int
	fmt.Scan(&w, &a, &b)

	answer := max(a, b) - min(a, b) - w
	if answer < 0 {
		fmt.Println(0)
	} else {
		fmt.Println(answer)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
