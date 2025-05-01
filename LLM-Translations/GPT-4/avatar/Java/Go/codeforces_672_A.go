package main

import (
	"fmt"
	"strconv"
)

func generateString() string {
	var sb string
	for i := 1; i <= 1000; i++ {
		sb += strconv.Itoa(i)
	}
	return sb
}

func main() {
	var n int
	fmt.Scan(&n)
	s := generateString()
	fmt.Println(string(s[n-1]))
}

// //End of Code
