package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	mapQuestion := make(map[int]int)

	countAc := 0
	countWaAll := 0

	for i := 0; i < m; i++ {
		var question int
		var waOrAc string
		fmt.Scan(&question)
		fmt.Scan(&waOrAc)

		countWa, exists := mapQuestion[question]

		if !exists {
			if waOrAc == "WA" {
				mapQuestion[question] = 1
			} else {
				mapQuestion[question] = -1
				countAc++
			}
		} else {
			if countWa < 0 {
				continue
			} else {
				if waOrAc == "WA" {
					mapQuestion[question] = countWa + 1
				} else {
					mapQuestion[question] = -countWa
					countAc++
					countWaAll += countWa
				}
			}
		}
	}

	fmt.Println(strconv.Itoa(countAc) + " " + strconv.Itoa(countWaAll))

}
// 
