package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var command, str string
	m := make(map[string]bool)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&command, &str)
		if strings.HasPrefix(command, "i") {
			m[str] = true
		} else {
			if m[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

// 
