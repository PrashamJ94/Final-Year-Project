package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)

	num, _ := strconv.Atoi(input)
	times := abs(num - 25)

	result := "Christmas" + repeat(" Eve", times)
	fmt.Println(result)
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func repeat(s string, count int) string {
	var result string
	for i := 0; i < count; i++ {
		result += s
	}
	return result
}
// 
