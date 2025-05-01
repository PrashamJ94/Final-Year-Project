package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	targ := []rune(s)
	m := make(map[rune]int)

	for _, char := range targ {
		m[char]++
	}

	ok := true
	for _, value := range m {
		if value != 2 {
			ok = false
			break
		}
	}

	if ok && len(m) == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// //End of Code
