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

	left := 0
	for _, i := range s {
		if i == ')' {
			left++
		} else {
			break
		}
	}

	left1 := 0
	right1 := 0

	for _, i := range s[left:] {
		if i == '(' {
			right1++
		} else if right1 > 0 {
			right1--
		} else {
			left1++
		}
	}

	left1 += left
	for i := 0; i < right1; i++ {
		s += ")"
	}
	for i := 0; i < left1; i++ {
		s = "(" + s
	}

	fmt.Println(s)
}
// 
