package main

import (
	"fmt"
)

func main() {
	var X, t int
	fmt.Scan(&X, &t)

	var answer int
	if X > t {
		answer = X - t
	} else if X <= t {
		answer = 0
	}

	fmt.Println(answer)
}
// 
