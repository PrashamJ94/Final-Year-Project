package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	total := 0

	for i := 0; i < len(s); i++ {
		for j := i + 1; j < len(s); j++ {
			if s[i] == s[j] {
				total++
			}
		}
	}

	if total == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
