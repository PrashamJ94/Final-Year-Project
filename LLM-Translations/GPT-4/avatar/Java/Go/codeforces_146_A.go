package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x, y, t, n int
	var str string

	fmt.Scan(&n)
	fmt.Scan(&str)

	chars := []rune(str)

	for i := 0; i < n; i++ {
		if chars[i] != '4' && chars[i] != '7' {
			t = 1
		}
	}
	if t == 1 {
		fmt.Println("NO")
	} else {
		for i := 0; i < n/2; i++ {
			x += int(chars[i] - '0')
		}
		for i := n - 1; i > (n/2)-1; i-- {
			y += int(chars[i] - '0')
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// //End of Code.
