package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d\n", &n, &m)
	var input string
	fmt.Scanln(&input)
	sa := strings.Count(input, "-")
	if n-sa < sa {
		sa = n - sa
	}
	var ss []string
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scanf("%d %d\n", &a, &b)
		b -= a
		if b%2 == 1 && b <= sa<<1 {
			ss = append(ss, "1\n")
		} else {
			ss = append(ss, "0\n")
		}
	}
	fmt.Print(strings.Join(ss, ""))
}

// End of Code

Please note, Go doesn't have direct equivalent for Python's `input().split()`. So the user input processing will be a bit different in Go. Above code assumes that the inputs are provided in a new line.
