package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	ABC := strings.Fields(input)
	var intABC []int
	for _, i := range ABC {
		j, err := strconv.Atoi(i)
		if err != nil {
			panic(err)
		}
		intABC = append(intABC, j)
	}

	count := 0
	total := 0
	for _, num := range intABC {
		if num == 5 {
			count++
		}
		total += num
	}

	if count == 2 {
		if total == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}
// End of Code
