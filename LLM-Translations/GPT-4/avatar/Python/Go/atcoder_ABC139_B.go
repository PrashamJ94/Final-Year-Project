package main

import (
	"fmt"
)

func main() {
	var a, b, hole, i int
	fmt.Scan(&a, &b)
	hole = 1
	i = 0
	check := true
	for check {
		if hole >= b {
			check = false
		} else {
			hole = a*(i+1) - i
			i += 1
		}
	}
	fmt.Println(i)
}

// End of Code
