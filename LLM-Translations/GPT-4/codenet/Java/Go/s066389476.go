package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scan(&input)
	solve(input)
}

func solve(input string) {
	a := []rune(input)
	if a[0] == a[1] || a[1] == a[2] || a[2] == a[0] {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}
// 
