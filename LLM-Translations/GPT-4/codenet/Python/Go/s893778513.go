package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	input := ""
	fmt.Scan(&input)
	l := strings.Split(input, " ")

	intSlice := make([]int, n)

	for i, num := range l {
		intSlice[i], _ = strconv.Atoi(num)
	}

	b := max(intSlice)
	s := sum(intSlice)

	if b < s-b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func max(slice []int) int {
	max := slice[0]
	for _, value := range slice {
		if value > max {
			max = value
		}
	}
	return max
}

func sum(slice []int) int {
	sum := 0
	for _, value := range slice {
		sum += value
	}
	return sum
}

// 
