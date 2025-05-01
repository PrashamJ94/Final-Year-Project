package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	if a%500 <= b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
