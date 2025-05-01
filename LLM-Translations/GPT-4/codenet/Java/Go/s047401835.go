package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	numbers := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&numbers[i])
	}

	count := 0

	for {
		divisible := true
		for i := range numbers {
			if numbers[i]%2 != 0 {
				divisible = false
				break
			}
			numbers[i] /= 2
		}

		if divisible {
			count++
		} else {
			break
		}
	}

	fmt.Println(count)
}

// 
