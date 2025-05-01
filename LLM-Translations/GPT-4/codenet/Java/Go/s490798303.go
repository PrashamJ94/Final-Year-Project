package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	mapOfLists := make(map[int][]int)

	var d, person int
	for i := 0; i < k; i++ {
		fmt.Scan(&d)
		for j := 0; j < d; j++ {
			fmt.Scan(&person)

			if _, exists := mapOfLists[person]; !exists {
				mapOfLists[person] = []int{}
			}
			mapOfLists[person] = append(mapOfLists[person], d)
		}
	}

	count := 0
	for i := 1; i <= n; i++ {
		if _, exists := mapOfLists[i]; !exists {
			count++
		}
	}

	fmt.Println(count)
}
// 
