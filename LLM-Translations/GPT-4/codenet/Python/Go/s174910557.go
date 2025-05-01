package main

import (
	"fmt"
)

func main() {
	var N int
	var S string

	fmt.Scan(&N)
	fmt.Scan(&S)

	ans := 1
	tmp := S[0]
	for _, s := range S {
		if s != rune(tmp) {
			ans++
			tmp = byte(s)
		}
	}

	fmt.Println(ans)
}

// 
