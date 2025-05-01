package main

import (
	"fmt"
	"sort"
)

type pair struct {
	key   int
	value int
}

func main() {
	var n int
	fmt.Scan(&n)
	v := make([]int, n)
	for i := range v {
		fmt.Scan(&v[i])
	}
	ve := make([]int, n/2)
	vo := make([]int, n/2)
	for i := 0; i < n/2; i++ {
		ve[i] = v[2*i]
		vo[i] = v[2*i+1]
	}
	ce := counter(ve)
	co := counter(vo)
	ans := n
	if ce[0].key != co[0].key {
		ans = n - ce[0].value - co[0].value
	} else if len(ce) == 1 && len(co) == 1 {
		ans = n - ce[0].value
	} else if len(ce) == 1 {
		ans = n - ce[0].value - co[1].value
	} else if len(co) == 1 {
		ans = n - ce[1].value - co[0].value
	} else {
		ans = min(n-ce[0].value-co[1].value, n-ce[1].value-co[0].value)
	}
	fmt.Println(ans)
}

func counter(arr []int) []pair {
	m := make(map[int]int)
	for _, v := range arr {
		m[v]++
	}
	pairs := make([]pair, 0, len(m))
	for k, v := range m {
		pairs = append(pairs, pair{k, v})
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].value > pairs[j].value
	})
	return pairs
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
