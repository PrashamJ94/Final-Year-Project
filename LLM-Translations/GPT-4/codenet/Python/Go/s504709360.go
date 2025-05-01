package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	if len(s) < 26 {
		for i := 0; i < 26; i++ {
			c := rune('a' + i)
			if !strings.ContainsRune(s, c) {
				fmt.Println(s + string(c))
				return
			}
		}
	} else {
		for i := 25; i > 0; i-- {
			if s[i-1] < s[i] {
				s1 := s[0 : i-1]
				for j := 0; j < 26; j++ {
					c := rune('a' + j)
					if c > rune(s[i-1]) && !strings.ContainsRune(s1, c) {
						fmt.Println(s1 + string(c))
						return
					}
				}
			}
		}
		fmt.Println(-1)
	}
}

// 
