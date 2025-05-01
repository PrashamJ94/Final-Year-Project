package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)
	var bool bool = x == 1
	var result int
	if !bool {
		result = 1
	} else {
		result = 0
	}
	fmt.Println(result)
}

// //End of Code
