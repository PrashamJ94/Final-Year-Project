package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	AB := strings.Split(input, " ")
	A, _ := strconv.Atoi(AB[0])
	B, _ := strconv.Atoi(AB[1])

	if A < 10 && B < 10 {
		fmt.Println(A * B)
	} else {
		fmt.Println(-1)
	}
}
// 
