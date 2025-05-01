package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int
	fmt.Scan(&a)
	funcA(a)
}

func funcA(a int) {
	digits := []int{}
	temp := a
	for temp != 0 {
		digits = append(digits, temp%10)
		temp = temp / 10
	}
	result := sum(digits)
	if result == 1 {
		fmt.Println("10")
	} else {
		fmt.Println(result)
	}
}

func sum(nums []int) int {
	total := 0
	for _, num := range nums {
		total += num
	}
	return total
}

// 
