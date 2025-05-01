package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scan(&input)
	doubleInput := input * 2
	var check string
	fmt.Scan(&check)

	if strings.Contains(doubleInput, check) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
