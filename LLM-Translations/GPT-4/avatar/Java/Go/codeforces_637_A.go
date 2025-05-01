package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	ara := make([]int, n)
	m := make(map[int]int)

	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		ara[i] = v
		if _, ok := m[v]; !ok {
			m[v] = 1
		} else {
			m[v]++
		}
	}

	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}

	mm := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]]; !ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		} else {
			mm[ara[i]]++
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		}
	}
}

// //End of Code
