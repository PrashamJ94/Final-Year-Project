package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	s := strings.Split(".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz", ":")
	k := make([][]rune, 9)
	for i := 0; i < 9; i++ {
		k[i] = []rune(s[i])
	}

	for n > 0 {
		var input string
		fmt.Scan(&input)
		c := []rune(input)
		l, a := -1, 0

		for i := 0; i < len(c); i++ {
			if c[i] != '0' {
				a = int(c[i] - '1')
				l = (l + 1) % len(k[a])
			} else if l >= 0 {
				fmt.Print(string(k[a][l]))
				l = -1
			}
		}
		fmt.Println()
		n--
	}
}

// 
