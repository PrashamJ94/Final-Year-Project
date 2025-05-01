package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	uniqueStrings := make(map[string]bool)

	for i := 0; i < n; i++ {
		var inputString string
		fmt.Scan(&inputString)
		uniqueStrings[inputString] = true
	}

	fmt.Println(len(uniqueStrings))
}

// 
