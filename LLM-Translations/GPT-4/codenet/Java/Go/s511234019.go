package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)

	if a%2 == 0 || b%2 == 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}
// 
