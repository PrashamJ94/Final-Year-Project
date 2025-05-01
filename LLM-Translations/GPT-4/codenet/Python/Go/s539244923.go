package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	if k%n == 0 {
		fmt.Println(n + k)
	} else {
		fmt.Println(k - n)
	}
}
// 
