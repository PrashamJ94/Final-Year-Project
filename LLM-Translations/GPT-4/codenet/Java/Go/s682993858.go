package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var s string
	for {
		fmt.Scan(&s)
		if s == "0" {
			break
		}
		sum := 0
		for i := 0; i < len(s); i++ {
			a := s[i]
			num, _ := strconv.Atoi(string(a))
			sum += num
		}
		fmt.Printf("%d\n", sum)
	}
}

// 
