package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	sRune, tRune := []rune(s), []rune(t)
	check := false

	for i := len(sRune) - len(tRune); i >= 0; i-- {
		check2 := true
		for j := 0; j < len(tRune); j++ {
			if sRune[i+j] != '?' && sRune[i+j] != tRune[j] {
				check2 = false
			}
		}
		if check2 {
			check = true
			for j := 0; j < len(tRune); j++ {
				sRune[i+j] = tRune[j]
			}
		}
		if check {
			break
		}
	}

	if check {
		for i := 0; i < len(sRune); i++ {
			if sRune[i] == '?' {
				fmt.Print("a")
			} else {
				fmt.Print(string(sRune[i]))
			}
		}
		fmt.Println()
	} else {
		fmt.Println("UNRESTORABLE")
	}
}

// 
