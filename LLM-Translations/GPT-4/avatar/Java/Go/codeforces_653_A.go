package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	a = unique(a)
	sort.Ints(a)

	found := false
	for i := 0; i < len(a); i++ {
		if i+1 < len(a) && i+2 < len(a) {
			if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
				found = true
			}
		}
	}

	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
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
// //End of Code
