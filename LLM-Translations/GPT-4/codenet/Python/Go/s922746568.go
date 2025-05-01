package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	rCnt := strings.Count(s, "R")
	gCnt := strings.Count(s, "G")
	bCnt := strings.Count(s, "B")

	ans := rCnt * gCnt * bCnt

	for i := 0; i < n; i++ {
		for d := 0; d < n; d++ {
			j := i + d
			k := j + d
			if k >= n {
				break
			}
			if s[i] != s[j] && s[j] != s[k] && s[k] != s[i] {
				ans -= 1
			}
		}
	}
	fmt.Println(ans)
}

// 
