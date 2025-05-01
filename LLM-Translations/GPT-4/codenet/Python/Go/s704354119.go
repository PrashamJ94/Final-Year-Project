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
	l := strings.Split(input, " ")

	max := -1e9
	min := 1e9
	sum := 0
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(l[i])
		sum += num
		if max < num {
			max = num
		}
		if min > num {
			min = num
		}
	}
	fmt.Println(min, max, sum)
}
// 
