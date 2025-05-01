package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second int
}

func main() {
	var n int
	fmt.Scan(&n)
	m := make([]Pair, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&m[i].first, &m[i].second)
	}
	sort.SliceStable(m, func(i, j int) bool {
		return m[i].first > m[j].first
	})
	a := m[0]
	for _, i := range m[1:] {
		if i.second > a.second {
			fmt.Println("Happy Alex")
			return
		}
		a = i
	}
	fmt.Println("Poor Alex")
}

// End of Code
