
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var input string
	var sum int

	for {
		_, err := fmt.Scanf("%s", &input)
		if err != nil {
			break
		}

		if input == "0" {
			break
		}

		sum = 0
		for _, char := range input {
			num, _ := strconv.Atoi(string(char))
			sum += num
		}
		fmt.Println(sum)
	}
}
// 

