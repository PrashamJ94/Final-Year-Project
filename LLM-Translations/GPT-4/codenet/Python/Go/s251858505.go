package main

import (
	"fmt"
	"strings"
)

func main() {
	var input1, input2 string
	fmt.Scanln(&input1)
	fmt.Scanln(&input2)

	count := 0
	for i := range input1 {
		if i < len(input2) && input1[i] == input2[i] {
			count++
		}
	}

	fmt.Println(count)
}
// 
