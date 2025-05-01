package main

import (
	"fmt"
)

func main() {
	var X, t int

	fmt.Scan(&X)
	fmt.Scan(&t)

	if X >= t {
		fmt.Println(X - t)
	} else if X < t {
		fmt.Print(0)
	}

}
// 
