package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	list1 := make([]int, a)
	list2 := make([]int, b)

	for i := 0; i < a; i++ {
		fmt.Scan(&list1[i])
	}
	for i := 0; i < b; i++ {
		fmt.Scan(&list2[i])
	}

	sort.Ints(list1)
	sort.Ints(list2)

	for i := 0; i < n; i++ {
		if contains(list1, i+1) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
	fmt.Println()
}

func contains(arr []int, val int) bool {
	for _, v := range arr {
		if v == val {
			return true
		}
	}
	return false
}

// //End of Code.
