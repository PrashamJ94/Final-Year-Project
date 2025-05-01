package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var input string
	fmt.Scanln(&input)

	numbers := strings.Split(input, " ")
	var x []int

	for _, num := range numbers {
		intNum, _ := strconv.Atoi(num)
		x = append(x, intNum)
	}

	for i := len(x) - 1; i >= 0; i-- {
		fmt.Print(x[i], " ")
	}
}

// 
