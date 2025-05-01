package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	remainder := 0
	result := 0

	result = (B - 1) / (A - 1)
	remainder = (B - 1) % (A - 1)

	if remainder != 0 {
		result += 1
	}

	fmt.Println(result)
}

// //End of Code
