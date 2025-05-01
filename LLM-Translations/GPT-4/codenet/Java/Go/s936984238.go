
package main

import (
	"fmt"
	"sort"
)

func main() {
	var number int
	score := make([]int, 0)

	for {
		fmt.Scan(&number)
		if number == 0 {
			break
		}

		score = make([]int, number)
		for i := 0; i < number; i++ {
			fmt.Scan(&score[i])
		}

		solve(score, number)
	}
}

func solve(score []int, number int) {
	sort.Ints(score)
	sum := 0
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}

// 
