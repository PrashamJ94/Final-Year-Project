package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	if N%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
