package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input")
		return
	}

	p := 97
	c := make([]rune, n)

	for i := 0; i < 4; i++ {
		for j := i; j < n; j += 4 {
			c[j] = rune(p)
		}
		p++
	}

	for i := 0; i < n; i++ {
		fmt.Print(string(c[i]))
	}
	fmt.Println()
}

// //End of Code
