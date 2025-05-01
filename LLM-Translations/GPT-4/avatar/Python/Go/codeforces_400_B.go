package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	c := make(map[int]bool)
	var s string
	for i := 0; i < n; i++ {
		fmt.Scan(&s)
		c[strings.Index(s, "S")-strings.Index(s, "G")] = true
	}
	flag := false
	for a := range c {
		if a < 0 {
			flag = true
			break
		}
	}
	if flag {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}

// End of Code
