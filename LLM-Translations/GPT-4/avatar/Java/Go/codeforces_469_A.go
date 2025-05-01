package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, levels int
	fmt.Scan(&n)
	fmt.Scan(&levels)
	var sum, sum2, sum3, count int
	arr := make([]int, levels)
	for i := 0; i < levels; i++ {
		fmt.Scan(&arr[i])
	}
	var level2 int
	fmt.Scan(&level2)
	level3 := levels + level2
	arr2 := make([]int, level3)
	for i := 0; i < len(arr); i++ {
		arr2[i] = arr[i]
	}
	for i := len(arr); i < level3; i++ {
		fmt.Scan(&arr2[i])
	}
	arr3 := make([]int, n)
	var j int
	for i := 0; i < n; i++ {
		j++
		arr3[i] = j
	}
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

// //End of Code
