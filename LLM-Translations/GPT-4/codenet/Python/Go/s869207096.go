package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var s string

	fmt.Scan(&n)
	fmt.Scan(&s)

	cnt := 1
	for i := 0; i < n-1; i++ {
		if s[i] == s[i+1] {
			continue
		} else {
			cnt++
		}
	}

	fmt.Println(cnt)
}
// 
