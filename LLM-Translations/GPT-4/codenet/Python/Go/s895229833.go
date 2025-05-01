package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	var input string
	fmt.Scan(&input)

	H := convertToIntArray(strings.Split(input, " "))

	countBest := 0
	countTmp := 0

	for i := 0; i < N-1; i++ {
		if H[i] >= H[i+1] {
			countTmp++
		} else {
			if countTmp > countBest {
				countBest = countTmp
			}
			countTmp = 0
		}
	}

	if countTmp > countBest {
		countBest = countTmp
	}

	fmt.Println(countBest)
}

func convertToIntArray(arr []string) []int {
	intArr := make([]int, len(arr))
	for i, v := range arr {
		intVal, err := strconv.Atoi(v)
		if err == nil {
			intArr[i] = intVal
		}
	}
	return intArr
}
// 
