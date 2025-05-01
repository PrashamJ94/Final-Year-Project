package main

import (
	"fmt"
	"strings"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	var S string
	fmt.Scan(&S)

	if S[A] == '-' && strings.Count(S, "-") == 1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
