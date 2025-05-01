package main

import (
	"fmt"
)

func main() {
	var high, low, sa int
	for i := 0; i < 7; i++ {
		fmt.Scan(&high)
		fmt.Scan(&low)
		sa = high - low
		fmt.Println(sa)
	}
}

// 
