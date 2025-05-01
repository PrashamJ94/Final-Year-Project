package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	if (A+B)%2 == 1 {
		fmt.Println("IMPOSSIBLE")
	} else {
		fmt.Println((A + B) / 2)
	}
}
// 
