package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var input string
	fmt.Scan(&input)

	s := strings.Split(input, "")
	sort.Strings(s)

	if s[0] == s[1] && s[0] != s[2] && s[2] == s[3] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
