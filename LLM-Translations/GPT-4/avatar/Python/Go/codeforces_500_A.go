package main

import (
	"fmt"
	"os"
)

func main() {
	var n, t int
	fmt.Scan(&n, &t)
	s := make([]int, n)
	for i := range s {
		fmt.Scan(&s[i])
	}
	currentCell := 0
	for currentCell < t {
		currentCell += s[currentCell]
		if currentCell == t {
			fmt.Println("YES")
			os.Exit(0)
		}
	}
	fmt.Println("NO")
}

// End of Code.
