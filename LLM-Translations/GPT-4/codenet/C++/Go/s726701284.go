package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	found := false

	for i := 'a'; i <= 'z'; i++ {
		count := strings.Count(s, string(i))
		if count == 0 {
			fmt.Println(string(i))
			found = true
			break
		}
	}

	if !found {
		fmt.Println("None")
	}
}
// 
