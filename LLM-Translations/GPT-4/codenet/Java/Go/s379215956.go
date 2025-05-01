package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	s1 := string(s[0])
	s2 := string(s[1])
	s3 := string(s[2])
	s4 := string(s[3])

	var a int

	if strings.EqualFold(s1, s2) {
		a = 1
	}
	if strings.EqualFold(s2, s3) {
		a = 1
	}
	if strings.EqualFold(s3, s4) {
		a = 1
	}

	if a == 1 {
		fmt.Println("Bad")
	} else {
		fmt.Println("Good")
	}
}

// 
