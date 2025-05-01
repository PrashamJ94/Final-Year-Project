package main

import (
	"fmt"
	"strings"
)

func main() {
	var c string
	fmt.Scan(&c)

	var ans []rune
	for _, ch := range c {
		if ch != 'B' {
			ans = append(ans, ch)
		} else if len(ans) > 0 {
			ans = ans[:len(ans)-1]
		}
	}

	fmt.Println(string(ans))
} //
