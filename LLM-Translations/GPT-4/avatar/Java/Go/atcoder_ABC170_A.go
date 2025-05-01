
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	inputArray := strings.Split(input, " ")

	result := 0
	for _, str := range inputArray {
		result++
		if str == "0" {
			break
		}
	}

	fmt.Println(result)
}

// //End of Code


