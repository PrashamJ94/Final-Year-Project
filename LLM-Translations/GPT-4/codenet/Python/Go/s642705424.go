package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	var S string
	fmt.Scan(&S)
	x := 1
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			x = x + 1
		}
	}
	fmt.Println(x)
}

// 
