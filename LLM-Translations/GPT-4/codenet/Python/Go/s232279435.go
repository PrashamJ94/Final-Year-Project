package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)

	ans := 0

	for i := 0; i < n; i++ {
		x := uniqueChars(s[:i+1])
		y := uniqueChars(s[i+1:])

		z := 0
		for _, w := range x {
			if strings.Contains(y, w) {
				z++
			}
		}
		if z > ans {
			ans = z
		}
	}
	fmt.Println(ans)
}

func uniqueChars(s string) string {
	var unique string
	for _, char := range s {
		if !strings.Contains(unique, string(char)) {
			unique += string(char)
		}
	}
	return unique
}

// 
