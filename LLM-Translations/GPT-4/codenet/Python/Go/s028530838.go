package main

import (
	"fmt"
	"unicode"
)

func main() {
	var x string
	fmt.Scan(&x)

	if unicode.IsLower(rune(x[0])) {
		fmt.Println("a")
	} else {
		fmt.Println("A")
	}
}

// 
