package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)

	if strings.Contains(a, "9") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
