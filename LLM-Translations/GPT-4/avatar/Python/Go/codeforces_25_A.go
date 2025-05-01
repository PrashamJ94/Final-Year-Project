package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	var list []int
	var input string
	fmt.Scan(&input)
	for _, v := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(v)
		list = append(list, num%2)
	}
	sum := 0
	for _, v := range list {
		sum += v
	}
	if sum == 1 {
		fmt.Println(indexOf(list, 1) + 1)
	} else {
		fmt.Println(indexOf(list, 0) + 1)
	}
}

func indexOf(array []int, element int) int {
	for i, v := range array {
		if v == element {
			return i
		}
	}
	return -1
}

// End of Code
