package main

import (
	"fmt"
	"strings"
)

func swapCase(s string) string {
	return strings.Map(func(r rune) rune {
		if r >= 'a' && r <= 'z' {
			return r - 'a' + 'A'
		} else if r >= 'A' && r <= 'Z' {
			return r - 'A' + 'a'
		}
		return r
	}, s)
}

func main() {
	var input string
	fmt.Scanln(&input)
	fmt.Println(swapCase(input))
}
// 
