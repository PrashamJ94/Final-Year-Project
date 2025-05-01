package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	ls := make([][2]int, n)
	for i := range ls {
		fmt.Scan(&ls[i][0], &ls[i][1])
	}

	sort.Slice(ls, func(i, j int) bool {
		return ls[i][0]+ls[i][1] > ls[j][0]+ls[j][1]
	})

	taka := 0
	aoki := 0
	for i := range ls {
		if i%2 == 0 {
			taka += ls[i][0]
		} else {
			aoki += ls[i][1]
		}
	}

	fmt.Println(taka - aoki)
}

// 
