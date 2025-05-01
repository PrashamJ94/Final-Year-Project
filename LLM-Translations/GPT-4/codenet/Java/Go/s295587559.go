package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, count int
	fmt.Scan(&n)

	num := make([]int, n)
	for i := 0; i < n; i++ {
		num[i] = i + 1
	}

	fmt.Scan(&count)

	var line [2]int
	for i := 0; i < count; i++ {
		var next string
		fmt.Scan(&next)

		pairs := strings.Split(next, ",")
		for j := 0; j < len(line); j++ {
			line[j], _ = strconv.Atoi(pairs[j])
			line[j]--
		}

		change := num[line[0]]
		num[line[0]] = num[line[1]]
		num[line[1]] = change
	}

	for i := 0; i < n; i++ {
		fmt.Println(num[i])
	}
}

// 
