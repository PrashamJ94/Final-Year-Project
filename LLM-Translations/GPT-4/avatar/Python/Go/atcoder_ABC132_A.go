package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	c := make(map[rune]int)
	for _, r := range S {
		c[r]++
	}

	Sa := make(map[rune]struct{})
	for _, r := range S {
		Sa[r] = struct{}{}
	}

	if len(Sa) != 2 {
		fmt.Println("No")
		return
	}

	for _, v := range c {
		if v != 2 {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}

// End of Code
