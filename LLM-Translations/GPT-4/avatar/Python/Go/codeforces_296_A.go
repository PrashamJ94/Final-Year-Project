package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var m string
	var possible = true
	fmt.Scan(&n)
	fmt.Scan(&m)

	s := strings.Split(m, " ")
	mMap := make(map[string]int)

	for _, word := range s {
		mMap[word]++
	}

	for _, v := range mMap {
		if v >= n/2+1 {
			possible = false
			break
		}
	}

	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
} // End of Code
