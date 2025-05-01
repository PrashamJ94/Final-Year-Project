package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	even := make(map[rune]int)
	odd := make(map[rune]int)
	for i, v := range s {
		if i%2 == 0 {
			even[v]++
		} else {
			odd[v]++
		}
	}
	fmt.Println(min(len(s)-(even['0']+odd['1']), len(s)-(even['1']+odd['0'])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of Code
