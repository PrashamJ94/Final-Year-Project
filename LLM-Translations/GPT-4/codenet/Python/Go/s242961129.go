package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	var A []int
	var input string
	fmt.Scan(&input)
	for _, x := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(x)
		A = append(A, num)
	}

	ans := abs(A[len(A)-1])
	A = append([]int{0}, A...)
	A = append(A, 0)
	diff := make([]int, N)

	for i := 1; i <= N; i++ {
		dif := abs(A[i]-A[i-1]) + abs(A[i]-A[i+1]) - abs(A[i-1]-A[i+1])
		ans += abs(A[i] - A[i-1])
		diff[i-1] = dif
	}

	for i := 0; i < N; i++ {
		fmt.Println(ans - diff[i])
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 
