package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	var s string
	fmt.Scanln(&s)

	for _, c := range s {
		if unicode.IsUpper(c) {
			c = unicode.ToLower(c)
			fmt.Print(string(c))
		} else if unicode.IsLower(c) {
			c = unicode.ToUpper(c)
			fmt.Print(string(c))
		} else {
			fmt.Print(string(c))
		}
	}

	fmt.Println()
}

// 
