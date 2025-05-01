package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	var n int
	fmt.Scan(&n)
	ans := 0
	for i := 0; i < n; i++ {
		var x string
		fmt.Scan(&x)
		a, b := 0, 0
		for _, j := range s {
			if string(j) == string(x[0]) {
				a += 1
			} else if string(j) == string(x[1]) {
				b += 1
			} else {
				ans = ans + min(a, b)
				a, b = 0, 0
			}
		}
		ans = ans + min(a, b)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

// End of Code
