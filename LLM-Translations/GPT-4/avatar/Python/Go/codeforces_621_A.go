package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, sum, od, ok int
	fmt.Scan(&n)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(lst)))
	for _, i := range lst {
		if i&1 == 1 {
			od++
		}
	}
	for i := 0; i < n; i++ {
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			if ok == 1 || od > 1 {
				sum += lst[i]
				od--
				if ok == 0 {
					ok = 1
				} else {
					ok = 0
				}
			}
		}
	}
	fmt.Println(sum)
}

// End of Code
