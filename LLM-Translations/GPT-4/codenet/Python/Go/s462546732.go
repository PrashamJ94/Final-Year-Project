package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	splitInput := strings.Split(input, " ")
	a, _ := strconv.Atoi(splitInput[0])
	b, _ := strconv.Atoi(splitInput[1])

	if a <= b {
		fmt.Println(a)
	} else {
		fmt.Println(a - 1)
	}
}
// 
