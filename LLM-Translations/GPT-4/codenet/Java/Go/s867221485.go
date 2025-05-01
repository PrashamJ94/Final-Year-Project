
package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	var s string
	fmt.Scan(&s)

	flag := false
	ans := 0
	hen := 0
	sha := 0
	dot := 0
	temp := 0
	first := true
	for i := 0; i < N; i++ {
		if s[i] == '#' {
			first = false
			if sha <= dot {
				ans += sha
				sha = 0
				dot = 0
				first = true
			} else {
				temp += dot
			}

			sha++
		} else {
			dot++
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	} else {
		temp += dot
	}

	fmt.Println(ans + dot)
}

// 


