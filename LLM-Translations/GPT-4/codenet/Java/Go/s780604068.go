package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	mapArray := make([]int, N*2)
	for i := 0; i < N*2; i++ {
		fmt.Scan(&mapArray[i])
	}

	sort.Ints(mapArray)

	max := 0
	for i := 0; i < N*2; i += 2 {
		max += min(mapArray[i], mapArray[i+1])
	}

	fmt.Println(max)

}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
