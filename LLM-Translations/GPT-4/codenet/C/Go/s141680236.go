package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func push(number int, stack []int) []int {
	stack = append(stack, number)
	return stack
}

func pop(stack []int) (int, []int) {
	top := len(stack) - 1
	value := stack[top]
	stack = stack[:top]
	return value, stack
}

func main() {
	var stack []int
	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		input := scanner.Text()
		if input == "+" {
			num1, stack := pop(stack)
			num2, stack := pop(stack)
			stack = push(num1+num2, stack)
		} else if input == "-" {
			num1, stack := pop(stack)
			num2, stack := pop(stack)
			stack = push(num1-num2, stack)
		} else if input == "*" {
			num1, stack := pop(stack)
			num2, stack := pop(stack)
			stack = push(num1*num2, stack)
		} else {
			num, _ := strconv.Atoi(strings.TrimSpace(input))
			stack = push(num, stack)
		}
	}

	result, _ := pop(stack)
	fmt.Println(result)
}

// 
