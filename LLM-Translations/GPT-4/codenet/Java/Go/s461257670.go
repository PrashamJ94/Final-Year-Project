package main

import (
	"fmt"
)

func main() {
	var count int
	fmt.Scan(&count)

	for i := 0; i < count; i++ {
		var y, m, d int
		fmt.Scan(&y, &m, &d)
		fmt.Println(Answer(y, m, d))
	}
}

func Answer(y int, m int, d int) int {
	result := 1

	if y%3 == 0 {
		result += 20 - d
	} else if m%2 == 0 {
		result += 19 - d
	} else {
		result += 20 - d
	}

	for m += 1; m <= 10; m++ {
		if y%3 == 0 {
			result += 20
		} else {
			if m%2 == 0 {
				result += 19
			} else {
				result += 20
			}
		}
	}

	for y += 1; y < 1000; y++ {
		if y%3 == 0 {
			result += 200
		} else {
			result += 195
		}
	}
	return result
}

// 
