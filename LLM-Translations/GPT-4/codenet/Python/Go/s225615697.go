package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	var input string
	fmt.Scan(&input)
	inputList := strings.Split(input, " ")

	a := make([]int, n)
	for i, v := range inputList {
		a[i], _ = strconv.Atoi(v)
	}

	m1 := int(sumAlternateSign(a) / 2)

	result := strconv.Itoa(m1)

	m := make([]int, n)
	m[0] = m1
	for i := 1; i < n; i++ {
		m[i] = a[i-1] - m[i-1]
	}

	output := make([]string, n)
	for i, v := range m {
		output[i] = strconv.Itoa(v * 2)
	}

	fmt.Println(strings.Join(output, " "))
}

func sumAlternateSign(a []int) int {
	sum := 0
	for i, v := range a {
		if i%2 == 0 {
			sum += v
		} else {
			sum -= v
		}
	}
	return sum
}

// 
