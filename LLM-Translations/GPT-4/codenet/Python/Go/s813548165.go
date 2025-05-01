package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	var S, T string

	fmt.Scan(&N)
	fmt.Scan(&S, &T)

	var charLists []string

	for i, char := range S {
		charLists = append(charLists, string(char))
		charLists = append(charLists, string(T[i]))
	}

	fmt.Println(strings.Join(charLists, ""))
}

// 
