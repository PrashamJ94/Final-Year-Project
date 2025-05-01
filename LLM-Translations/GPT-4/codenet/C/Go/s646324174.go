package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

var top int
var S [10000]int

func push(x int) {
	top++
	S[top] = x
}

func pop() int {
	top--
	return S[top+1]
}

func main() {
	var a, b int
	var s string
	top = 0
	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		s = scanner.Text()
		if s == "+" {
			b = pop()
			a = pop()
			push(a + b)
		} else if s == "-" {
			b = pop()
			a = pop()
			push(a - b)
		} else if s == "*" {
			b = pop()
			a = pop()
			push(a * b)
		} else {
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}

	fmt.Println(pop())
}
// 
