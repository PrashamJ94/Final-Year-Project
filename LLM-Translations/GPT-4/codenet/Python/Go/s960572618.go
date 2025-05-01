package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	inputs := strings.Split(input, " ")

	a := inputs[0]
	b := inputs[1]
	c := inputs[2]

	if a == b && b == c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

//
