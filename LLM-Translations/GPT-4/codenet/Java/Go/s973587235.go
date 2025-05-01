package main

import (
	"fmt"
)

func main() {
	var n, h int
	fmt.Scan(&n)

	minN := 0
	fmt.Scan(&minN)
	minN--

	for i := 0; i < n-1; i++ {
		fmt.Scan(&h)
		if minN == h {
			minN = h
		} else if minN == h-1 {
			minN = h - 1
		} else if minN < h-1 {
			minN = h - 1
		} else if minN > h {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

// 
