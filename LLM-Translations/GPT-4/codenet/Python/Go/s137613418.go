package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	A := loadList()

	if n == len(unique(A)) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func loadList() []int {
	var input string
	fmt.Scan(&input)
	strSlice := strings.Split(input, " ")
	intSlice := make([]int, len(strSlice))

	for i, str := range strSlice {
		intSlice[i], _ = strconv.Atoi(str)
	}

	return intSlice
}

func unique(intSlice []int) []int {
	keys := make(map[int]bool)
	list := []int{}

	for _, entry := range intSlice {
		if _, value := keys[entry]; !value {
			keys[entry] = true
			list = append(list, entry)
		}
	}

	return list
}

// 
