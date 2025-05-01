package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	count := 0
	for a > 0 && b > 0 {
		count++
		a--
		b--
	}

	ans := a/2 + b/2
	fmt.Println(count, ans)
}

// //End of Code
