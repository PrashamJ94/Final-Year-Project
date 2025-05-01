package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	answer := "No"
	if a+b >= c {
		answer = "Yes"
	}
	fmt.Println(answer)
}

// 
