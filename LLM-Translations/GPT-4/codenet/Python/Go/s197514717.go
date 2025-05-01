package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	ABC := strings.Split(input, " ")
	A, _ := strconv.Atoi(ABC[0])
	B, _ := strconv.Atoi(ABC[1])
	C, _ := strconv.Atoi(ABC[2])

	fmt.Println(max([]int{10*A + B + C, 10*B + C + A, 10*C + A + B}))
}

func max(numbers []int) int {
	max := numbers[0]
	for _, number := range numbers {
		if number > max {
			max = number
		}
	}
	return max
}

// 
