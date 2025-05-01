package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a [5]int
	dic := make(map[int]int)

	for i := 0; i < 5; i++ {
		fmt.Scan(&a[i])

		if a[i]%10 == 0 {
			dic[i] = 0
		} else {
			dic[i] = a[i]%10 - 10
		}
	}

	minNum := indexOfMinValue(dic)
	aSum := sum(a[:])
	delete(dic, minNum)
	fmt.Println(abs(sumValues(dic)) + aSum)
}

func indexOfMinValue(m map[int]int) int {
	minIndex := 0
	minValue := m[0]

	for k, v := range m {
		if v < minValue {
			minValue = v
			minIndex = k
		}
	}

	return minIndex
}

func sum(arr []int) int {
	total := 0

	for _, v := range arr {
		total += v
	}

	return total
}

func abs(n int) int {
	if n < 0 {
		return -n
	}

	return n
}

func sumValues(m map[int]int) int {
	total := 0

	for _, v := range m {
		total += v
	}

	return total
}
// 
